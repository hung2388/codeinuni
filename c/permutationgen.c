#include <stdio.h>
int n;
int arr[500000];
int used[5000];
void try(int k)
{
    if(k>n-1)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            arr[k]=i;
            used[i]=1;
            try(k+1);
            used[i]=0;
        }
    }
}

int main()
{
    for(int i=0;i<5000;i++)
    {
        used[i]=0;
    }
    scanf("%d",&n);
    try(0);
}