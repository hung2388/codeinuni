import numpy as np
import matplotlib.pyplot as plt
Day=[0,0.25,0.5,1,2,3,4,5,6,8,10]
DrugRelease=[2.5,3.6,5.3,9.5,14.0,16.5,18.8,21.5,23.2,26.8,28.4]
x=np.array(Day)
y=np.array(DrugRelease)
def fitting(a,b,n):
    parameters=np.polyfit(a,b,n)
    model_val=np.polyval(parameters,a)
    residuals=model_val-b
    return parameters,model_val,residuals

for order in [2, 3]:
    parameter, model_value, res = fitting(x, y, order)
    SumSquaredResiduals = np.sum(res**2)
    plt.figure(figsize=(10, 5))
    plt.scatter(x, y, color='pink', label='Data')
    x_smooth = np.linspace(0, 10, 100)
    plt.plot(x_smooth, np.polyval(parameter, x_smooth), color='green', label=f'Order {order} Fit')
    plt.title(f'Drug Release - Order {order} Polynomial')
    plt.legend()
    plt.show()
    plt.figure(figsize=(10, 4))
    plt.bar(x, res, color='orange', width=0.2)
    plt.axhline(0, color='black', linewidth=1)
    plt.title(f'Residuals for Order {order} (Sum Squared Residuals: {SumSquaredResiduals:.2f})')
    plt.show()