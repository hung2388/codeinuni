#include <stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d ",&a,&b);
    int A[a][b];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    scanf("%d %d",&c,&d);
    int B[c][d];
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<d;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    int C[a][d];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<d;j++)
        {
            C[i][j]=0;
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<d;j++)
        {
            for(int k=0;k<b;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<d;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}