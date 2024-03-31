import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

plt.style.use('https://github.com/dhaitz/matplotlib-stylesheets/raw/master/pitayasmoothie-light.mplstyle')

def lineal_model(x, a, b):
    return a*x + b

t_entropy, entropy = np.genfromtxt('EntropyVsTime200x200.txt', unpack=True, usecols=(0,1))
fig, axes = plt.subplots(figsize=(6, 6))

axes.plot(t_entropy, entropy, '-', color='black', label=r'$Entropy(t)$')




# Se ajustan demás detalles del gráfico.
axes.set_xlabel('t', fontsize=12)
axes.set_ylabel('Entropy', fontsize=12)

axes.legend(loc='upper left')   #
axes.grid(True, linestyle='--')

axes.set_title("Entropy vs t.", fontsize=14)
plt.tight_layout()





















# entropyD = np.roll(entropy,1)
# diff = entropy - entropyD
# diff = diff[1:]
# indices = np.where(diff > 0.005)
# print(len(indices[0]))
# print("indices: ", indices[0])
#axes.plot(t_entropy[indices[0]], entropy[indices[0]], '-', color='yellow', label=r'$Entropy(t)$')







fig.savefig('EntropyPlot.png')
