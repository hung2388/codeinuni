#include <stdio.h>
#define maxx 1000
typedef struct{
    int x; int y;
}node;

int check[maxx][maxx];
node queue[maxx*maxx];
int dist[maxx][maxx];
int bfs(int n, int m,int r,int c)
{
    int sti=0,ei=0;
    dist[r][c]=0;
    queue[ei++]=(node){r,c};
    check[r][c]=1;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while(sti<ei)
    {
        node thi=queue[sti++];
        int x=thi.x;
        int y=thi.y;
        for(int i=0;i<4;i++)
        {
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(dx<0||dy<0||dx==n||dy==m)
            {
                return dist[x][y]+1;
            }
            if(check[dx][dy]==0)
            {
                dist[dx][dy]=dist[x][y]+1;
                queue[ei++]=(node){dx,dy};
                check[dx][dy]=1;
            }
        }
    }
    return -1;
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
    printf("%d",bfs(n,m,r-1,c-1));
}