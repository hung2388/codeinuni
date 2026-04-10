#include<stdio.h>
int main()
{
    int n,q;
    int cnt=0;
    scanf("%d %d",&n,&q);
    int need[n+1];
    for(int i=0;i<=n;i++)
    {
        need[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        need[c]=1;
        if(need[q-c]==1) cnt++;
    }
    printf("%d",cnt);
}