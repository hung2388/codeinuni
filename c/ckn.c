#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int C[1000][1000];
int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[0][i]=1;
        C[i][i]=1;
        C[1][i]=i;
        C[i-1][i]=i;
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=j;i++)
        {
            if(i==j) C[i][j]==1;
            else
            C[i][j]=(C[i-1][j-1]+C[i][j-1])%((int)pow(10,9)+7);
            if(i==k)
            break;
        }
    }
    printf("%d",C[k][n]);
}
