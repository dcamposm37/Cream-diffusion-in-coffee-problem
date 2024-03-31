import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

plt.style.use('https://github.com/dhaitz/matplotlib-stylesheets/raw/master/pitayasmoothie-light.mplstyle')


def lineal_model(x, a, b):
    return a*x + b

t, size= np.genfromtxt('SizeVsTime_.txt', unpack=True, usecols=(0, 1))

entropy = np.genfromtxt('EntropyVsTime200x200.txt', unpack=True, usecols=(1))

#Se encuentra el valor hasta el cual se debe ajustar.
maximumValueEntropy = np.max(entropy)
tolerance = 0.2
max = maximumValueEntropy-tolerance
index = np.where(entropy < max) #Índices donde se debe hacer el ajuste.
index = index[0]
t_fit = t[index]
size_fit = size[index]

# Ajuste
parameters, covarian_matrix = curve_fit(lineal_model, t_fit, size_fit)
a, b = parameters



sizeAdjusted = lineal_model(t_fit, a, b)

r2, _ = pearsonr(size_fit, sizeAdjusted)


fig, axes = plt.subplots(figsize=(6, 6))


axes.scatter(t, size, marker='.', color='black', label= 'Size(t)')

axes.plot(t_fit, sizeAdjusted, color='yellow',label=r'{} $t$ + {} ($R^2$ ={})'.format(round(b,2),round(a,3),round(r2,4)))

# Se ajustan demás detalles del gráfico.

axes.set_xlabel('t', fontsize=12)
axes.set_ylabel(f'$(\sum r^2_i/ N)$', fontsize=12)
axes.set_title("Squared size of the drop as a function of time")
axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
fig.savefig('sizeVsTimePlot_.png')
