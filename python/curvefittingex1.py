import numpy as np
import matplotlib.pyplot as plt
Day=[0,0.25,0.5,1,2,3,4,5,6,8,10]
DrugRelease=[2.5,3.6,5.3,9.5,14.0,16.5,18.8,21.5,23.2,26.8,28.4]
x=np.array(Day)
y=np.array(DrugRelease)
def fitting(a,b):
    parameters=np.polyfit(a,b,1)
    model_val=np.polyval(parameters,a)
    return parameters,model_val

parameter,model_value=fitting(x,y)
plt.figure(figsize=(10, 6))
plt.scatter(Day, DrugRelease, color='pink', label='Data', zorder=5)
plt.plot(Day, model_value, color='green', label=f'Linear Fit: y = {parameter[0]:.2f}x + {parameter[1]:.2f}')
plt.title('Drug Release from Nanoparticles over Time')
plt.xlabel('Day')
plt.ylabel('Micrograms drug released')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)
plt.show()