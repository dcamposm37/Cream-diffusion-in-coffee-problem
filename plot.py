import numpy as np
import matplotlib.pyplot as plt


n1, x1, y1 = np.genfromtxt('datos0.txt', unpack=True, usecols=(0, 1, 2))
n2, x2, y2 = np.genfromtxt('datos1.txt', unpack=True, usecols=(0, 1, 2))

plt.style.use('seaborn-v0_8')

fig, axes = plt.subplots(figsize=(6, 6))

#axes.plot(x1, y1, '.', color='black', label=r'$(x,y)_{I}$')
axes.plot(x2, y2, '.', color='black', label=r'$(x,y)_{F}$')

axes.set_xlim(-100, 100)
axes.set_ylim(-100, 100)


# Se ajustan demás detalles del gráfico.

axes.set_xlabel('x', fontsize=12)
axes.set_ylabel('y', fontsize=12)
axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
axes.set_title("y vs x", fontsize=14)
plt.tight_layout()
plt.show()
#fig.savefig('plot.pdf')
