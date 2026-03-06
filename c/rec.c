#include <stdio.h>
#include <limits.h>
int res=INT_MIN;
int min(int a,int b,int c)
{
    int d=a<b?a:b;
    return d<c?d:c;
}
int max(int a,int b,int c)
{
    int d=a>b?a:b;
    return d>c?d:c;
}
int main()
{
    int n;
    int a,b,c,d;
    scanf("%d",&n);
    int xmin=INT_MAX,ymin=INT_MAX,xmax=INT_MIN,ymax=INT_MIN;
    while(n--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        xmin=min(xmin,a,c);
        xmax=max(xmax,a,c);
        ymin=min(ymin,b,d);
        ymax=max(ymax,b,d);
    }
    res=(xmax-xmin)*(ymax-ymin);
    printf("%d",res);
}