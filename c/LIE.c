#include <stdio.h>
int n,q;
int arr[500000];
int check()
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if (sum==q) return 1;
    else return 0;
}
void try(int k)
{
    if(k>n-1)
    {
        if(check())
        {
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=1;i<=q;i++)
    {
        arr[k]=i;
        try(k+1);
    }
}

int main()
{
    scanf("%d %d",&n,&q);
    try(0);
}