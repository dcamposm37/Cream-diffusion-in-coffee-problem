import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

def proposed_model(x, tau,A):
    return A*np.exp(-x/tau)

t, molecules= np.genfromtxt('moleculesVsTime.txt', unpack=True, usecols=(0, 1))


# Ajuste
parameters, covarian_matrix = curve_fit(proposed_model, t, molecules, p0=[400,100])
tau = parameters[0]
A = parameters[1]

moleculesAdjusted = proposed_model(t, tau, A)

r2, _ = pearsonr(molecules, moleculesAdjusted)


fig, axes = plt.subplots(figsize=(6,6))


axes.plot(t, molecules, '-', color='black', label='Molecules(t)')

#axes.plot(t, proposed_model(t,300000,50), color='red',label= f'tau={tau}, r2={r2}')

# Se ajustan demás detalles del gráfico.

axes.set_xlabel('t', fontsize=12)
axes.set_ylabel('Number of molecules', fontsize=12)
axes.set_title("Number of molecules in the container vs t")
axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
fig.savefig('moleculesVsTimePlot.png')
