#include <stdio.h>
#include <string.h>
int A[2000];
int idx=0;
int pidx=0;
void push(int k)
{
    A[idx++]=k;
}
void pop()
{
    if(pidx==idx)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n",A[pidx++]);        
    }
}
int main()
{
    char s[200];
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"#")==0)
        {
            break;
        }
        else if(strcmp(s,"PUSH")==0)
        {
            int a;
            scanf("%d",&a);
            push(a);
        }
        else if(strcmp(s,"POP")==0)
        {
            pop();
        }
    }
}