#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int step;
}moment;
moment moments[1000000];
int front=0,rear=0;

void push(int x, int y,int z)
{
    moments[rear].x=x;
    moments[rear].y=y;
    moments[rear++].step=z;
}
moment pop()
{
    return moments[front++];
}
int min(int a, int b)
{
    return a<b?a:b;
}
    int visited[1001][1001];

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    memset(visited,0,sizeof(visited));
    push(0,0,0);
    visited[0][0]=1;
    while(front<rear)
    {
        moment cur=pop();
        int m=cur.x;
        int n=cur.y;
        int h=cur.step;
        if(m==c||n==c)
        {
            printf("%d",h);
            return 0;
        }
        if(!visited[m][b])
        {
            push(m,b,h+1);
            visited[m][b]=1;
        }
        if(!visited[a][n])
        {
            push(a,n,h+1);
            visited[a][n]=1;
        }
        if(!visited[m][0])
        {
            push(m,0,h+1);
            visited[m][0]=1;
        }
        if(!visited[0][n])
        {
            push(0,n,h+1);
            visited[0][n]=1;
        }
        int trans1=min(m,b-n);
        int la=m-trans1,lb=n+trans1;
        if(!visited[la][lb])
        {
            push(la,lb,h+1);
            visited[la][lb]=1;
        }
        
        int trans2=min(a-m,n);
        int ra=m+trans2,rb=n-trans2;
        if(!visited[ra][rb])
        {
            push(ra,rb,h+1);
            visited[ra][rb]=1;
        }       
    }
    printf("-1");
}