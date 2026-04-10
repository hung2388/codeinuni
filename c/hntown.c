#include <stdio.h>
#include <math.h>
void Try(int n, int a, int b, int c)
{
    if(n==1)
    {
        printf("%d %d\n",a,c);
        return;
    }
    Try(n-1,a,c,b);
    printf("%d %d\n",a,c);
    Try(n-1,b,a,c);
}
int main()
{
    int n,a,b,c;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    printf("%d\n",(int)pow(2,n)-1);
    Try(n,a,c,b);
}