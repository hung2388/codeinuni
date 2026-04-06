#num=input("num ")
#print(num[0:8:2])
#print(num[-1])
number=998124.2345
print(f"hello {number:.2f}")
print(f"{number:010}") #in trong khung rộng 10 kí tự, và thêm số 0 vào đầu
print(f"{number:,}")#grand format
print(f"{number:+,.2f}")
for i in range(11):
    print(i,end="") #end="" là ko xuống dòng