import numpy as np
from scipy.linalg import lu, solve_triangular
A = np.array([[2, 3, 1],
              [4, 7, 7],
              [-2, 4, 5]])
b = np.array([1, 2, 3])
P, L, U = lu(A)
b_new = np.dot(P.T, b)
y = solve_triangular(L, b_new, lower=True)
x = solve_triangular(U, y, lower=False)
print("A:\n",A)
print("b:",b)
print("P:\n", P)
print("L:\n", L)
print("U:\n", U)
print("\nsolution x:", x)
