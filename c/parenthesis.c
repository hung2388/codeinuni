#include <stdio.h>
#include <string.h>
char A[2000];
int idx=-1;
void push(char k)
{
    idx++;
    A[idx]=k;
}
char pop()
{
    if(idx==-1)
    {
        return NULL;
    }
    else
    {
        return A[idx--];
    }
}

int main()
{
    int chx=1;
    char s[200];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(i==0&&(s[i]==']'||s[i]==')'||s[i]=='}'))
        {
            chx=0;
            break;
        }
        else if(s[i]=='['||s[i]=='('||s[i]=='{')
        {
            push(s[i]);
        }
        else if(s[i]==']'||s[i]==')'||s[i]=='}')
        {
            char a=pop();
            if(!((a=='('&&s[i]==')')||(a=='['&&s[i]==']')||(a=='{'&&s[i]=='}')))
            {
                chx=0;
                break;
            }
        }
    }
    if(idx!=-1) chx=0;
    printf("%d",chx);
}