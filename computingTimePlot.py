import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr

plt.style.use('https://github.com/dhaitz/matplotlib-stylesheets/raw/master/pitayasmoothie-light.mplstyle')


size_NO, time_NO  = np.genfromtxt('computingTime_NO.txt', unpack=True, usecols=(0,1))
size_O, time_O = np.genfromtxt('computingTime_O.txt', unpack=True, usecols=(0,1))

fig, axes = plt.subplots(2,1,figsize=(6, 6))

#Normalización:

size_NO = size_NO/size_NO[0]
time_NO = time_NO/time_NO[0]

size_O = size_O/size_O[0]
time_O = time_O/time_O[0]


axes[0].plot(size_NO, time_NO, '.', color='black', label=r'Unoptimized computation time (size)')
axes[1].plot(size_O, time_O, '.', color='blue', label=r'Optimized computation time (size)')

# Se ajustan demás detalles del gráfico.
for i in range(0,2):
    axes[i].set_xlabel('Size normalized.', fontsize=12)
    axes[i].set_ylabel('Computing time normalized.', fontsize=12)

    axes[i].legend(loc='upper left')   #
    axes[i].grid(True, linestyle='--')

    axes[i].set_title("Computing time vs Size.", fontsize=14)

plt.tight_layout()
fig.savefig('computingTimePlot.png')
