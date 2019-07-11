import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("cuerda.txt")
datos2=np.genfromtxt("cuerda2.txt")

t=datos[:,0]
x=datos[:,2]
xp=datos[:,3]

t2=datos2[:,0]
xp2=datos2[:,3]

plt.figure()
plt.subplot(3,1,1)
plt.plot(t,x)
plt.xlabel("L")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condiciones iniciales")

plt.subplot(3,1,2)
plt.plot(t,xp)
plt.xlabel("L")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condiciones presente")

plt.subplot(3,1,3)
plt.plot(t2,xp2)
plt.xlabel("L")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condicion Futura")

plt.subplots_adjust(hspace=.7)
plt.savefig("cuerdacaso1.png")

caso2=np.genfromtxt("cuerdacaso2.txt")
caso2b=np.genfromtxt("cuerda2caso2.txt")

tc2=caso2[:,0]
xc2=caso2[:,2]
xpc2=caso2[:,3]

t2c2=caso2b[:,0]
xp2c2=caso2b[:,3]

plt.figure()
plt.subplot(3,1,1)
plt.plot(tc2,xc2, color='g')
plt.xlabel("L")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condiciones iniciales")

plt.subplot(3,1,2)
plt.plot(tc2,xpc2, color='g')
plt.xlabel("L")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condiciones presente")

plt.subplot(3,1,3)
plt.plot(t2c2,xp2c2, color='g')
plt.xlabel("L")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condicion Futura")

plt.subplots_adjust(hspace=.7)
plt.savefig("cuerdacaso2.png")

