#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int delta=b*b-4*a*c;
    if(delta<0)
    {
        printf("NO SOLUTION\n");
        return 0;
    }
    else if(delta==0)
    {
        float sol=-b/(2*a);
        printf("%.2f",sol);
        return 0;
    }
    else
    {
        float x2=(-b+sqrt(delta))/(2*a);
        float x1=(-b-sqrt(delta))/(2*a);
        printf("%.2f %.2f",x1,x2);
        return 0;
    }
}