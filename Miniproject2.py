import numpy as np
import matplotlib.pyplot as plt




# Setup

x_ = np.linspace(-np.pi,np.pi,10000)

n_1 = 3

n_2 = 5

n_3 = 10

n_4 = 50





# An coefficients. no bn since its 0

def an(n):

    n = int(n)

    if (n%2 != 0):

        return 8/((n)**2)

    else:

        return -8/((-n)**2)


# Fourier Series function

def fourierSeries(N,t):

    a0 = (-4*(np.pi*np.pi))/3

    partialSums = a0

    for n in range(1,N):

        try:

            partialSums = partialSums + an(n)*np.cos(n*t)

        except:

            print("pass")

            pass

    return partialSums

f1 = []
f2 = []
f3 = []
f4 = []


for i in x_:

    f1.append(fourierSeries(n_1,i))

for i in x_:

    f2.append(fourierSeries(n_2,i))

for i in x_:

    f3.append(fourierSeries(n_3,i))

for i in x_:

    f4.append(fourierSeries(n_4,i))



plt.plot(x_,f1,color="red",label="Fourier series approximation")

plt.title("Fourier Series approximation number for N = "+str(n_1))

plt.legend()

plt.figure()



plt.plot(x_,f2,color="green",label="Fourier series approximation")

plt.title("Fourier Series approximation number for N = "+str(n_2))

plt.legend()

plt.figure()



plt.plot(x_,f3,color="yellow",label="Fourier series approximation")

plt.title("Fourier Series approximation number for N = "+str(n_3))

plt.legend()

plt.figure()



plt.plot(x_,f4,color="blue",label="Fourier series approximation")

plt.title("Fourier Series approximation number for N = "+str(n_4))

plt.legend()

plt.figure()

plt.show()