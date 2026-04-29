import matplotlib.pyplot as plt

def plot_method(grid, approx, h, method_name):
    exact = []

    for x in grid:
        exact.append(df(x))

    plt.plot(grid, approx, 'o--', label=f"{method_name}, h={h}")


def f(x):
    return x**4-3*x**3+2*x**2-x+5

def df(x):
    return 4*x**3-9*x**2+4*x-1
def FE(f,df,a,b,h):
    grid=[]
    diff=[]
    err=0
    i=a
    while(i+h<=b):    
        grid.append(i)
        y=i+h
        sol=(f(y)-f(i))/h
        err+=abs(df(i)-sol)
        diff.append(sol)
        i=y
    err/=len(grid)
    return grid,diff,err

def BE(f,df,a,b,h):
    grid=[]
    diff=[]
    i=a+h
    err=0
    while(i<=b):    
        grid.append(i)
        y=i-h
        sol=(f(i)-f(y))/h
        err+=abs(df(i)-sol)
        diff.append(sol)
        i+=h
    err/=len(grid)
    return grid,diff,err

def CD(f,df,a,b,h):
    grid=[]
    diff=[]
    i=a+h
    err=0
    while(i+h<=b):    
        grid.append(i)
        l=i-h
        r=i+h
        sol=(f(r)-f(l))/(2*h)
        err+=abs(df(i)-sol)
        diff.append(sol)
        i+=h
    err/=len(grid)
    return grid,diff,err

def main():
    a=float(input("input a: "))
    b=float(input("input b: "))
    h1=float(input("input h1: "))
    h2=float(input("input h2: "))
    h3=float(input("input h3: "))
    gfh1,dfh1,efh1=FE(f,df,a,b,h1)
    gfh2,dfh2,efh2=FE(f,df,a,b,h2)
    gfh3,dfh3,efh3=FE(f,df,a,b,h3)
    gbh1,dbh1,ebh1=BE(f,df,a,b,h1)
    gbh2,dbh2,ebh2=BE(f,df,a,b,h2)
    gbh3,dbh3,ebh3=BE(f,df,a,b,h3)
    gcdh1,dcdh1,ecdh1=CD(f,df,a,b,h1)
    gcdh2,dcdh2,ecdh2=CD(f,df,a,b,h2)
    gcdh3,dcdh3,ecdh3=CD(f,df,a,b,h3)
    exact = []
    for x in gfh1:
        exact.append(df(x))
    plt.figure(figsize=(10,6))
    plt.plot(gfh1, exact, 'k', linewidth=2, label="Exact f'(x)")
    plt.plot(gfh1, dfh1, 'r', label=f"FE, h={h1}")
    plt.plot(gfh2, dfh2, 'g', alpha=0.7, label=f"FE, h={h2}")
    plt.plot(gfh3, dfh3, 'b', alpha=0.5, label=f"FE, h={h3}")
    plt.plot(gbh1, dbh1, 'k', label=f"BE, h={h1}")
    plt.plot(gbh2, dbh2, 'y', alpha=0.7, label=f"BE, h={h2}")
    plt.plot(gbh3, dbh3, 'm', alpha=0.5, label=f"BE, h={h3}")
    plt.plot(gcdh1, dcdh1, 'c', label=f"CD, h={h1}")
    plt.plot(gcdh2, dcdh2, 'orange', alpha=0.7, label=f"CD, h={h2}")
    plt.plot(gcdh3, dcdh3, 'pink', alpha=0.5, label=f"CD, h={h3}")
    plt.title("Comparison of Exact and Approximate Derivatives")
    plt.xlabel("x")
    plt.ylabel("f'(x)")
    plt.grid(True)
    plt.legend()
    plt.show()

main()