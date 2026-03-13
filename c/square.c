#include <stdio.h>
#include <math.h>
int main()
{
    int cnt=0;
    int n;
    int d;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d);
        if(sqrt(d)==(int)sqrt(d)) cnt++;
    }
    printf("%d",cnt);
}