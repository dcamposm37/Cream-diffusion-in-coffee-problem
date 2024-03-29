import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from qbstyles import mpl_style
mpl_style(dark=False)

def sqrt_model(x, a, b):
    return a*np.sqrt(x) + b

#n1, x1, y1 = np.genfromtxt('datos0.txt', unpack=True, usecols=(0, 1, 2))
t_entropy, entropy = np.genfromtxt('EntropyVsTime.txt', unpack=True, usecols=(0, 1))
t_size, size= np.genfromtxt('SizeVsTime.txt', unpack=True, usecols=(0, 1))

# Ajuste 
a, b, covarian_matrix = curve_fit(sqrt_model, t_size, size)

t_fit = np.linspace(t_size[0], t_size[-1], 100) 

#plt.style.use('seaborn-v0_8')

fig1, axes1 = plt.subplots(figsize=(6, 6))
fig2, axes2 = plt.subplots(figsize=(6, 6))

axes1.scatter(t_entropy, entropy, marker= '.', color='black', label=r'$Entropy(t)$')
axes2.scatter(t_size, size, marker= '.', color='black', label=r'$Size(t)$')
axes2.plot(t_fit, sqrt_model(t_fit, a, b), marker= '.', color='black', label=r'$squared fit$')
#axes.plot(x1, y1, '.', color='black', label=r'$(x,y)_{I}$')
#axes.plot(x2, y2, '.', color='black', label=r'$(x,y)_{F}$')

#axes.set_xlim(-100, 100)
#axes.set_ylim(-100, 100)


# Se ajustan demás detalles del gráfico.
axes1.set_xlabel('time', fontsize=12)
axes1.set_ylabel('Entropy', fontsize=12)
axes2.set_xlabel('time', fontsize=12)
axes2.set_ylabel('Size', fontsize=12)

# axes.set_xlabel('x', fontsize=12)
# axes.set_ylabel('y', fontsize=12)
axes1.legend(loc='upper left')   #
axes1.grid(True, linestyle='--')
axes2.legend(loc='upper left')   #
axes2.grid(True, linestyle='--')
#axes.set_title("y vs x", fontsize=14)
# plt.tight_layout()
#plt.show()
fig1.savefig('entropy.pdf')
fig2.savefig('size.pdf')
