#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    int d;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d);
        sum+=d;
    }
    printf("%d",sum);
}
