import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

def proposed_model(x, tau):
    return np.exp(-x/tau);

t, molecules= np.genfromtxt('moleculesVsTime.txt', unpack=True, usecols=(0, 1))

# Ajuste
parameters, covarian_matrix = curve_fit(proposed_model, t, molecules)
tau = parameters

moleculesAdjusted = proposed_model(t, tau)

r2, _ = pearsonr(molecules, moleculesAdjusted)


fig, axes = plt.subplots((6, 6))


axes.scatter(t, molecules, marker='.', color='black', label='Molecules(t)')

axes.plot(t, moleculesAdjusted, color='red',label=r'{} $e^{{-t/{tau}}}$  $R^2$ = {}'.format(round(tau,5),round(r2,4)))

# Se ajustan demás detalles del gráfico.

axes.set_xlabel('t', fontmolecules=12)
axes.set_ylabel('Number of molecules', fontmolecules=12)
axes.set_tittle("Number of molecules in the container vs t")
axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
fig.savefig('moleculesVsTimePlot.pdf')
