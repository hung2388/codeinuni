M=int(input())
#A=[]
#B=[]
C=[]
A=list(map(int,input().split()))
B=list(map(int,input().split()))
#for i in range(M):
#   A.append(int(input()))
#for i in range(M):
#    B.append(int(input()) )
for i in range(M):
    C.append(A[i]+B[i])
print(A)
print(B)
print(C)