#include<stdio.h>
int n,q;
int cnt=0;
int A[2000];
void try(int str,int sum)
{
    if(sum==q)
    {
        cnt++;
        return;
    }
    for(int i=str;i<n;i++)
    {
            if(sum+A[i]<=q)
            {
                try(i+1,sum+A[i]);
            }
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