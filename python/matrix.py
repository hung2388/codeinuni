m,n,p=map(int,input().split())
A=[]
B=[]
for i in range(m):
    row=list(map(int,input().split()))
    A.append(row)
for i in range(m):
    row=list(map(int,input().split()))
    B.append(row)
C = [[0]*p for _ in range(m)]
for i in range(m):
    for j in range(p):
        for k in range(n):
            C[i][j] += A[i][k] * B[k][j]
print("Matrix A:")
for row in A:
    print(*row)
print("Matrix B:")
for row in B:
    print(*row)
print("Matrix C:")
for row in C:
    print(*row)