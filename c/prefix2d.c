#include <stdio.h>
int main()
{
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d ",&A[i][j]);
        }
    }
    int cnt=0;
    for(int i=0;i+k<=n;i++)
    {
        for(int j=0;j+k<=n;j++)
        {
            int sum=0;
            for(int a=i;a<i+k;a++)
            {
                for(int b=j;b<j+k;b++)
                {
                    sum+=A[a][b];
                }
            }
            if(sum==m) cnt++;
        }
    }
    printf("%d",cnt);
}