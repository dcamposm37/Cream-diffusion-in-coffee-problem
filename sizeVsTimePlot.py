import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

plt.style.use('https://github.com/dhaitz/matplotlib-stylesheets/raw/master/pitayasmoothie-light.mplstyle')

def lineal_model(x, a, b):
    return a*x + b

t, size= np.genfromtxt('SizeVsTime.txt', unpack=True, usecols=(0, 1))

# Ajuste
parameters, covarian_matrix = curve_fit(lineal_model, t, size)
a, b = parameters

t_fit = np.linspace(t[0], t[-1], 100)


sizeAdjusted = lineal_model(t, a, b)

r2, _ = pearsonr(size, sizeAdjusted)


fig, axes = plt.subplots(figsize=(6, 6))


axes.scatter(t, size, marker='.', color='black', label= 'Size(t)')

axes.plot(t, sizeAdjusted, color='red',label=r'{} $t^{{1/2}}$ + {}  $R^2$ ={}'.format(round(b,2),round(a,3),round(r2,4)))

# Se ajustan demás detalles del gráfico.

axes.set_xlabel('t', fontsize=12)
axes.set_ylabel('Size', fontsize=12)
axes.set_title("Size of the drop  Vs t")
axes.legend()
axes.grid(True, linestyle='--')
fig.savefig('sizeVsTimePlot.png')
