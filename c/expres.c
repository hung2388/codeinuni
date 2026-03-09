#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define maxx 100000
#define mod 1000000007
int Num[maxx];
char Op[maxx];
int numi=0;
int opi=0;
void pushN(int k)
{
    Num[numi++]=k;
}
void pushOp(char k)
{
    Op[opi++]=k;
}
int popN()
{
    return Num[--numi];
}
char popOp()
{
    return Op[--opi];
}
int prio(char op)
{
    if(op=='*') return 1;
    else return 0;
}
int cal(int num1,int num2, char op)
{
    if(op=='+') return ((long long)num1+num2)%mod;
    else if(op=='*') return ((long long)num1*num2)%mod;
}

int main()
{
    char s[maxx];
    scanf("%s",s);
    int c=1;
    if(!isdigit(s[0]))
    {
        c=0;
    }
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            char a[20];
            int j=0;
            while(isdigit(s[i]))
            {
                a[j++]=s[i++];
            }
            i--;
            a[j]='\0';
            int d=atoi(a)%mod;
            pushN(d);
        }
        else
        {
            if(!isdigit(s[i+1]))
            {
                c=0;
                break;
            }
            while (opi!=0&&prio(Op[opi-1])>=prio(s[i]))
            {
                int x2=popN();
                int x1=popN();
                char op=popOp();
                pushN(cal(x1,x2,op));
            }
            pushOp(s[i]);
        }
    }
    if(c==0)
    {
        printf("NOT_CORRECT");
        return 0;
    }
    while(numi>1)
    {
        int x2=popN();
        int x1=popN();
        char op=popOp();
        pushN(cal(x1,x2,op));
    }
    printf("%d",popN());
}