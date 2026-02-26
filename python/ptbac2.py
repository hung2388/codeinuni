from math import sqrt
a,b,c=map(int,input("nhập 3 số: ").split())
delta=b**2-4*a*c;
if delta<0:
    print("pt vô nghiệm")
elif delta==0:
    res=-b/(2*a)
    print(res)
else:
    res1=(-b+sqrt(delta))/(2*a)
    res2=(-b-sqrt(delta))/(2*a)
    print(res1)
    print(res2)