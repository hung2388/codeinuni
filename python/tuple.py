n=int(input())
data =[]
for i in range(n):
    name,age,score=input().split()
    data.append((name,int(age),float(score)))
data.sort(key=lambda x:(x[0],-x[1],-x[2]))
for i in data:
    print(i)
