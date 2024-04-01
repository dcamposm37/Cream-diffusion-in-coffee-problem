import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

plt.style.use('https://github.com/dhaitz/matplotlib-stylesheets/raw/master/pitayasmoothie-light.mplstyle')

def model(x, a, b):
    return a*np.power(x,2) + b

docName = 'EntropyVsTime'
docSize = np.array(('50x50','100x100','150x150','200x200','250x250','300x300','350x350'))
t_entropy = np.genfromtxt('EntropyVsTime200x200.txt', unpack=True, usecols=(0))
numberValues = 7
entropy = np.empty(numberValues)
t_equilibrium = np.empty(numberValues)
sizes = np.empty(numberValues)
tolerance = 0.2
max = 4.1 - tolerance #Con una grilla de 8x8, el valor máximo de la entropía será aproximadamente 4.1


for ii in range (0,numberValues):
    name = docName + docSize[ii] + ".txt"
    entropy = np.genfromtxt(name, unpack=True, usecols=(1,))
    #Se encuentra el valor donde se alcanza el equilibrio.
    index = np.where(entropy < max) #Índices donde se debe hacer el ajuste.
    index = index[0]
    t_equilibrium[ii] = t_entropy[index][-1] #El último índice es donde aproximadamente se alcanza el equilibrio.
    indexX= docSize[ii].find('x')
    sizes[ii] = float(docSize[ii][0:indexX])


if(np.all(t_equilibrium == t_equilibrium[0]) or (len(index)==0)):
    print("Hacen falta más iteraciones para encontrar el equilibrio de la entropía de todos los tamaños.")
    exit()

parameters, covarian_matrix = curve_fit(model, sizes, t_equilibrium)
a, b = parameters

tEqAdjusted = model(sizes, a, b)

r2, _ = pearsonr(t_equilibrium,tEqAdjusted)


fig, axes = plt.subplots(figsize=(6, 6))

axes.plot(sizes, t_equilibrium, '.', color='black', label=r'$t_{eq}(size)$')

axes.plot(sizes, tEqAdjusted, color='yellow',label=r'{} $sizes^2$ + {} ($R^2$ ={})'.format(round(b,2),round(a,3),round(r2,4)))


# Se ajustan demás detalles del gráfico.
axes.set_xlabel('Size', fontsize=12)
axes.set_ylabel(r'$t_{eq}$', fontsize=12)

axes.legend(loc='upper left')   #
axes.grid(True, linestyle='--')

axes.set_title("Entropy equilibirum vs size.", fontsize=14)
plt.tight_layout()
fig.savefig('EntropyDifferentSizesPlot.png')
