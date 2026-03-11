a=input().split()
for i in range (0,len(a),1):
    for j in range(i,len(a),1):
        print(a[i:j+1])
