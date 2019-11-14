import os
import numpy as np
import matplotlib.pyplot as plt

plt.figure()

data = np.loadtxt("data.dat")

plt.subplot(1,2,1)
t = data[:,0]
v = data[:,1]
x = data[:,2]

plt.plot(t, v)
plt.title("v vs t")
plt.xlabel('t')
plt.ylabel('v')

plt.subplot(1,2,2)

plt.plot(x, v)

plt.title("x vs v")
plt.xlabel('x')
plt.ylabel('v')

plt.savefig("grafica.png")