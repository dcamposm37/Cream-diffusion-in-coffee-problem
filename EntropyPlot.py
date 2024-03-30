import numpy as np
import matplotlib.pyplot as plt

t_entropy, entropy = np.genfromtxt('EntropyVsTime200x200.txt', unpack=True, usecols=(0,1))
fig, axes = plt.subplots(figsize=(6, 6))


axes.scatter(t_entropy, entropy, marker='.', color='black', label=r'$Entropy(t)$')

# Se ajustan demás detalles del gráfico.
axes.set_xlabel('t', fontsize=12)
axes.set_ylabel('Entropy', fontsize=12)

axes.legend(loc='upper left')   #
axes.grid(True, linestyle='--')

axes.set_title("Entropy vs t", fontsize=14)
plt.tight_layout()

fig.savefig('EntropyPlot.pdf')
