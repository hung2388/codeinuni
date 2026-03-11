X=list(map(int,input().split()))
Y=list(map(int,input().split()))
C=[]
C=[i for i in X for j in Y if i%j==0 ]
print(C)