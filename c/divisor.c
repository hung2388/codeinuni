#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[200];
    int j=0;
    for(int i=-n;i<=n;i++)
    {
        if(i==0) continue;
        if(n%i==0)
        {
            A[j++]=i;
        }
    }
    int s=sizeof(A)/sizeof(A[0]);
    j=0;
    while(1)
    {
        printf("%d ",A[j]);
        if(A[j]==n) break;
        j++;
    }
}