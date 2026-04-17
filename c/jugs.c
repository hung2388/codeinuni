#include <stdio.h>
#include <string.h>
//for memset
typedef struct{
    int a; int b;
    int step;
}stage;

stage ue[100000];
int front=0,rear=0;

void push(int a, int b, int c)
{
    ue[rear].a=a;
    ue[rear].b=b;
    ue[rear++].step=c;
}
stage pop()
{
    return ue[front++];
}
int min(int a,int b)
{
    if (a<b) return a;
    return b;
}

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int visited[1001][1001];
    memset(visited,0,sizeof(visited));
    push(0,0,0);
    visited[0][0]=1;
    while(front<rear)
    {
        stage this=pop();
        if(this.a==c||this.b==c)
        {
            printf("%d",this.step);
            return 0;
        }

        if(!visited[a][this.b])
        {
            visited[a][this.b]=1;
            push(a,this.b,this.step+1);
        }
        if(!visited[this.a][b])
        {
            visited[this.a][b]=1;
            push(this.a,b,this.step+1);
        }
        if(!visited[this.a][0])
        {
            visited[this.a][0]=1;
            push(this.a,0,this.step+1);
        }
        if(!visited[0][this.b])
        {
            visited[0][this.b]=1;
            push(0,this.b,this.step+1);
        }
        //this.a -> this. b
        int t1=min(this.a,b-this.b);
        int la=this.a-t1,lb=this.b+t1;
        if(!visited[la][lb])
        {
            visited[la][lb]=1;
            push(la,lb,this.step+1);
        }
        int t2=min(a-this.a,this.b);
        int ra=this.a+t2,rb=this.b-t2;
        if(!visited[ra][rb])
        {
            visited[ra][rb]=1;
            push(ra,rb,this.step+1);
        }
    }
    printf("-1");
}