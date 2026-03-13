#include <stdio.h>
int main()
{
    int n,k;
    int cnt=0;
    int sum=0;
    scanf("%d %d",&n,&k);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<k;i++)
    {
        sum+=A[i];
    }
    if(sum%2==0)
    {
        cnt++;
    }
    int i=0,j=k;
    while(j<n)
    {
        sum-=A[i++];
        sum+=A[j++];
        if(sum%2==0)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
}