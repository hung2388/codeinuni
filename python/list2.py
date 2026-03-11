M=input().split()
N=int(input())
res =[]
for i in range(1,N+1):
    for j in range(0,len(M)):
        res.append(M[j]+str(i))
print(res)