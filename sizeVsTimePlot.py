import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

plt.style.use('https://github.com/dhaitz/matplotlib-stylesheets/raw/master/pitayasmoothie-light.mplstyle')

def lineal_model(x, a, b):
    return a*x + b

t, size= np.genfromtxt('SizeVsTime.txt', unpack=True, usecols=(0, 1))

# Ajuste
parameters, covarian_matrix = curve_fit(lineal_model, t[:2*10**3], size[:2*10**3])
a, b = parameters

t_fit = t[:3*10**3]


sizeAdjusted = lineal_model(t_fit, a, b)

r2, _ = pearsonr(size[:3*10**3], sizeAdjusted)


fig, axes = plt.subplots(figsize=(6, 6))


axes.scatter(t, size, s=4, color='black', label= 'Size(t)')

axes.plot(t_fit, sizeAdjusted, color='red',label=r'{} $t$ + {} ($R^2$ ={})'.format(round(b,2),round(a,3),round(r2,4)))

# Se ajustan demás detalles del gráfico.

axes.set_xlabel('Time', fontsize=12)
axes.set_ylabel(f'$(\sum r^2_i/ N)$', fontsize=12)
axes.set_title("Squared size of the drop in function of time")
axes.legend()
axes.grid(True, linestyle='--')
fig.savefig('sizeVsTimePlot.png')
