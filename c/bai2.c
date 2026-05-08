#include <stdio.h>
#include <string.h>
#define maxx 10000
int sta[maxx];
int idx;
void push(int k)
{
    sta[idx++]=k;
}
int pop()
{
    idx--;
    return sta[idx];
}
int main()
{
    char s[30];
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"#")==0)
        {
            break;
        }
        else if(strcmp(s,"PUSH")==0)
        {
            int d;
            scanf("%d",&d);
            push(d);
        }
        else if(strcmp(s,"POP")==0)
        {
            if(idx<=0)
            {
                printf("NULL");
            }
            else
            {
                printf("%d\n",pop());
            }
        }
    }
}
