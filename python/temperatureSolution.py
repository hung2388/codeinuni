import numpy as np
import matplotlib.pyplot as plt
L=1 #length of rod
T=0.1 # Time interval
k=1 #k
N=30 # length step
M=1000 # time step
dx=L/N
dt=T/M

alp=(k*dt)/(dx**2)

x=np.linspace(0,L,N+1) 
#print(x)
u=np.zeros((M+1,N+1))
u[0,:]=1000*np.cos(x)+800*np.sin(x)
#print(u0)
for j in range(0, M):
    for i in range(1, N):
        u[j+1,i]=u[j,i]+alp*(u[j,i+1]-2*u[j,i]+u[j,i-1])
    u[j+1, 0] = 0.01
    u[j+1, N] = 0.01
plt.figure(figsize=(8, 6))
plt.imshow(u, extent=[0, L, 0, T], aspect='auto', cmap='hot', origin='lower')
plt.colorbar(label='Temperature (u)')
plt.title("Temperature change over Space (X) and Time (T)")
plt.xlabel("Space (x)")
plt.ylabel("Time (t)")
plt.show()