import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
Day=[0,0.25,0.5,1,2,3,4,5,6,8,10]
DrugRelease=[2.5,3.6,5.3,9.5,14.0,16.5,18.8,21.5,23.2,26.8,28.4]
x = np.array(Day)
y = np.array(DrugRelease)
Day_full = Day + [12,16,21]
DrugRelease_full = DrugRelease + [28.4,28.5,29.5]
x_full = np.array(Day_full)
y_full = np.array(DrugRelease_full)
def fitting(a,b,n):
    parameters = np.polyfit(a,b,n)
    return parameters
def exponential_model(t,C,a):
    return C * (1 - np.exp(-a * t))
p_exp,_ = curve_fit(exponential_model,x,y,p0=[10,2])
x_pred = np.linspace(0,21,200)
plt.figure(figsize=(12,8))
plt.scatter(x_full,y_full,color='pink',label='Complete Data (0-21 days)',zorder=5)
colors = ['red','green','blue','purple']
labels = ['1st Order','2nd Order','3rd Order']
for i, order in enumerate([1,2,3]):
    params = fitting(x,y,order) 
    y_plot = np.polyval(params,x_pred)
    plt.plot(x_pred,y_plot,color=colors[i],label=f'Predictive {labels[i]}')
plt.plot(x_pred,exponential_model(x_pred,*p_exp),color='black',
         linestyle='--',label='Predictive Exponential')
plt.ylim(0,50) 
plt.title('Model Prediction vs Actual Data (Day 0 to 21)')
plt.xlabel('Day')
plt.ylabel('Micrograms drug released')
plt.legend()
plt.grid(True,linestyle='--',alpha=0.7)
plt.show()