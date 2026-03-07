#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define maxx 1000
int Num[maxx];
int Op[maxx];
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
    if(op=='+') return num1+num2;
    else if(op=='*') return num1*num2;
}

int main()
{
    char s[200];
    fgets(s,200,stdin);
    
}