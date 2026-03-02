#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxx 200
char A[maxx];
char Op[maxx];
double num[maxx];
int Opi=0;
int numi=0;
int dot=0;
void pushOp(char k)
{
    Op[Opi++]=k;
}
void pushNum(double k)
{
    num[numi++]=k;
}
char popOp()
{
    return Op[--Opi];
}
double popNum()
{
    return num[--numi];
}
double cal(double a,double b,char op)
{
    if(op=='+') return a+b;
    else if(op=='-') return a-b;
    else if(op=='*') return a*b;
    else if(op=='/') return a/b;
}
int prio(char op)
{
    if(op=='*'||op=='/') return 1;
    else return 0;
}

int main()
{
    scanf ("%s",&A);
    for(int i=0;i<strlen(A);i++)
    {
        if(isdigit(A[i]))
        {
            char s[20];
            int j=0;
            while(isdigit(A[i])||A[i]=='.')
            {
                s[j++]=A[i++];
                if(A[i]=='.') dot=1;
            }
            s[j]='\0';
            i--;
            double k=atof(s);
            pushNum(k);
        }
        else if(A[i]=='(')
        {
            pushOp('(');
        }
        else if(A[i]==')')
        {
            while(1)
            {
                char op=popOp();
                if(op=='(') break;
                double b=popNum();
                double a=popNum();
                pushNum(cal(a,b,op));
            }
        }
        else
        {
            if(Opi>0&&Op[Opi-1]!='('&&prio(Op[Opi-1])>=prio(A[i]))
            {
                char op=popOp();
                double b=popNum();
                double a=popNum();
                pushNum(cal(a,b,op));
            }
            pushOp(A[i]);
        }
    }
    while(Opi>0)
    {
        char op=popOp();
        double b=popNum();
        double a=popNum();
        pushNum(cal(a,b,op));
    }
    double res=popNum();
    if(dot==1||res!=(int)res) printf("%.1lf",res);
    else printf("%d",(int)res);
}