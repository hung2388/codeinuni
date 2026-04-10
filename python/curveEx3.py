import numpy as np
import matplotlib.pyplot as plt
Day=[0,0.25,0.5,1,2,3,4,5,6,8,10]
DrugRelease=[2.5,3.6,5.3,9.5,14.0,16.5,18.8,21.5,23.2,26.8,28.4]
x=np.array(Day)
y=np.array(DrugRelease)
def fitting(a,b):
    parameters=np.polyfit(a,b,1)
    model_val=np.polyval(parameters,a)
    residuals=model_val-b
    return parameters,model_val,residuals
parameter, model_value, res = fitting(x, y)
SumSquaredResiduals = np.sum(res**2)
print(f"The Sum Squared Residuals is: {SumSquaredResiduals:.2f}")