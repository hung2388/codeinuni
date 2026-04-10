#include <stdio.h>
#include <stdlib.h>
int n;
int A[1000][1000];
int C[1000];
int R[1000];
int Dm[1000];
int Dp[1000];
int cnt=0;
int sol=0;
int check(int i,int j)
{
    if(R[i]==1||C[j]==1||Dm[n+i-j]==1||Dp[i+j]==1)
    {
        return 0;
    }
    return 1;
}
void Try(int r)
{
    if(r==n)
    {
        sol++;
        return;
    }
    if(R[r]==1)
    {
        Try(r+1);
        return;
    }
    for(int c=0;c<n;c++)
    {
        if(check(r,c))
        {
            R[r]=1;
            C[c]=1;
            Dm[n+r-c]=1;
            Dp[r+c]=1;
            A[r][c]=1;
            Try(r+1);
            R[r]=0;
            C[c]=0;
            Dm[n+r-c]=0;
            Dp[r+c]=0;
            A[r][c]=0;
        }
    }
    
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        C[i]=0;
        R[i]=0;
        Dm[i]=0;
        Dp[i]=0;
        Dp[2*i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
            if(A[i][j]==1)
            {
                cnt++;
                R[i]=1;
                C[j]=1;
                Dm[n+i-j]=1;
                Dp[i+j]=1;
            }
        }
    }
    Try(0);
    printf("%d",sol);
}