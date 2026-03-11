M=int(input())
A=[]
B=[]
C=[]
for i in range(M):
    A.append(int(input()))
for i in range(M):
    B.append(int(input()))
for i in range(M):
    C.append(A[i]+B[i])
print(A)
print(B)
print(C)