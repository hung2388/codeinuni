import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
day = np.array([0, 0.25, 0.5, 1, 2, 3, 4, 5, 6, 8, 10])
drug_release = np.array([2.5, 3.6, 5.3, 9.5, 14.0, 16.5, 18.8, 21.5, 23.2, 26.8, 28.4])
def exponential_model(t, C, a):
    return C * (1 - np.exp(-a * t))
initial_estimates = [10, 2]
params, covariance = curve_fit(exponential_model, day, drug_release, p0=initial_estimates)
C_best, a_best = params
y_pred = exponential_model(day, C_best, a_best)
ssr_exp = np.sum((y_pred - drug_release)**2)
plt.figure(figsize=(10, 6))
plt.scatter(day, drug_release, color='pink', label='Experimental Data', zorder=5)
x_smooth = np.linspace(0, 10, 100)
y_smooth = exponential_model(x_smooth, C_best, a_best)
plt.plot(x_smooth, y_smooth, color='blue', label=f'Exponential Fit (C={C_best:.2f}, a={a_best:.2f})')
plt.title('Gray-box Model: Exponential Drug Release')
plt.xlabel('Day')
plt.ylabel('Micrograms drug released')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)
plt.show()
print(f"Best-fit parameters: C = {C_best:.4f}, a = {a_best:.4f}")
print(f"Sum of Squared Residuals (SSR): {ssr_exp:.4f}")