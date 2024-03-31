import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

plt.style.use('https://github.com/dhaitz/matplotlib-stylesheets/raw/master/pitayasmoothie-light.mplstyle')

def proposed_model(x,tau,A):
    return A*np.exp(-x/(tau*np.power(10,6)))

t, molecules= np.genfromtxt('moleculesVsTime.txt', unpack=True, usecols=(0, 1))


# Se ajusta al modelo propuesto. Se explica la elección de valores iniciales en el informe.
parameters, covarian_matrix = curve_fit(proposed_model, t, molecules, p0=[3.3,400])
tau = parameters[0]
A = parameters[1]

moleculesAdjusted = proposed_model(t, tau, A)

r2, _ = pearsonr(molecules, moleculesAdjusted)


fig, axes = plt.subplots(figsize=(6,6))


axes.plot(t, molecules, '.', color='black', label='Molecules(t)')

axes.plot(t, proposed_model(t,tau,A), color='yellow',label= r'tau={}$\times 10^6$, r2={} , ${}e^{{\frac{{-x}}{{\tau}}}}$'.format(round(tau,3), round(r2,4), round(A,2)))

# Se ajustan demás detalles del gráfico.

axes.set_xlabel('t', fontsize=12)
axes.set_ylabel('Number of molecules', fontsize=12)
axes.set_title("Number of molecules in the container vs t")
axes.legend(loc='upper right')
axes.grid(True, linestyle='--')
fig.savefig('moleculesVsTimePlot.png')
