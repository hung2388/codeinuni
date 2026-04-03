#include <stdio.h>
int n;
int arr[500000];
int check()
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1&&arr[i+1]==1) return 0;
    }
    return 1;
}
void try(int k)
{
    if(k>n-1)
    {
        if(check())
        {
            for(int i=0;i<n;i++)
            {
                printf("%d",arr[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=0;i<=1;i++)
    {
        arr[k]=i;
        try(k+1);
    }
}

int main()
{
    scanf("%d",&n);
    try(0);
}