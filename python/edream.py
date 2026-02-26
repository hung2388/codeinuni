from math import factorial
a=2/9801
a*=2**(1/2)
b=0
i=0
while 1:
    tu=factorial(4*i)*(1103+26390*i)
    mau=(factorial(i)**4)*(396**(4*i))
    if (tu/mau)<1e-15:
        break
    b=b+tu/mau
    i+=1
b*=a
b=1/b
print(b)
