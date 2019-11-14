import os
import numpy as np
import matplotlib.pyplot as plt

plt.figure()

datax = np.loadtxt("datavx.dat")
datay = np.loadtxt("datavy.dat")


x = datavx[:,1]
y = datavy[:,1]

plt.plot(x, y)
plt.title("x vs y")
plt.xlabel('x')
plt.ylabel('y')

plt.savefig("grafica.png")