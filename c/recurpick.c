#include <stdio.h>
int A[200];
int n;
int q;
int cnt=0;
void try(int k,int sum)
{
    if(sum==q)
    {
        cnt++;
        return;
    }
    if(sum>q)
    {
        return;
    }
    for(int i=k;i<n;i++)
    {
        if(sum+A[i]<=q)
        try(i+1,sum+A[i]);
    }
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    try(0,0);
    printf("%d",cnt);
}