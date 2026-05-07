#include<stdio.h>
#include <limits.h>
#define maxx 1000
int check[maxx][maxx];
int min=INT_MAX;
void tryy(int n,int m, int r, int c,int step)
{
    if(r==n||r<0||c==m||c<0)
    {
        if(step<min) min=step;
        return;
    }
    check[r][c]=1;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<4;i++)
    {
        int dx=dir[i][0];
        int dy=dir[i][1];
        int a=r+dx;
        int b=c+dy;
        if(check[a][b]==0)
        {
            tryy(n,m,a,b,step+1);
        }
    }
    check[r][c]=0;
}

int main()
{
    int n,m,r,c; 
    scanf("%d %d %d %d",&n,&m,&r,&c);
    int A[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&A[i][j]);
            if(A[i][j]==1)
            {
                check[i][j]=1;
            }
        }
    }
    tryy(n,m,r-1,c-1,0);
    if(min!=INT_MAX) printf("%d",min);
    else printf("-1");
}