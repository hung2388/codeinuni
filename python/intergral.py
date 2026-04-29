def f(x):
    return x**4+2*x**2+1
def exact(a,b):
    return (b**5-a**5)/5+2*(b**3-a**3)/3+(b-a)

def CTHT(f,a,b):
    return (b-a)*(f(a)+f(b))/2

def CTHTMR(f,a,b,N):
    h=(b-a)/N
    s=0
    for i in range(1,N):
        x=a+i*h
        s+=f(x)
    return h*((f(a)+f(b))/2+s)

def main():
    a=float(input("Input a: "))
    b=float(input("Input b: "))
    exact_val=exact(a,b)
    print(f"Exact integral = {exact_val:.2f}")
    trap=CTHT(f,a,b)
    print("\nTrapezoidal:")
    print(f"Approx = {trap:.2f}")
    print(f"Error = { abs(exact_val-trap):.2f}")
    for N in [2,10,20]:
        approx=CTHTMR(f,a,b,N)
        err=abs(exact_val-approx)
        print(f"Expanded Trapezoidal N={N}")
        print(f"Approx = {approx:.2f}")
        print(f"Error ={err:.2f}")
main()