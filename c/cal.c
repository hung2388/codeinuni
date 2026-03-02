#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxx 100 
char A[maxx];
char Op[maxx];
double num[maxx];
int idxOp=0;
int idxNum=0;
void pushNum(double k)  {   num[idxNum++]=k;    }
void pushOp(char k) {   Op[idxOp++]=k;  }
char popOp(){   return Op[--idxOp]; }
double popNum(){    return num[--idxNum];}
double cal(double a,double b, char op)
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
    scanf("%s",A);
    int a=strlen(A);
    for(int i=0;i<a;i++)
    {
        if(isdigit(A[i])||A[i]=='.')
        {
            char s[20];
            int j=0;
            while(isdigit(A[i])||A[i]=='.')
            {
                s[j++]=A[i++];
            }
            s[j]='\0';
            i--;
            double num=atof(s);
            pushNum(num);
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
            while(idxOp>0&&Op[idxOp-1]!='('&&prio(Op[idxOp-1])>=prio(A[i]))
            {
                char op = popOp();
                double b = popNum();
                double a = popNum();
                pushNum(cal(a,b,op));
            }
            pushOp(A[i]);
        }
    }
    while(idxOp>0)
    {
        char op = popOp();
        double b = popNum();
        double a = popNum();
        pushNum(cal(a,b,op));
    }
    double res=popNum();
    if(res!=(int)res)printf("%.1lf",res);
    else printf("%d",(int)res);
}