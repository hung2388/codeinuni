#include <stdio.h>
#include <string.h>
#define max 1000
char A[max];
char B[max];
char C[max];
char D[max];
void add2 (char A[], char B[])
{
    int car=0;
    int a=strlen(A);
    int b=strlen(B);
    if(a<b)
    {
        strcpy(C,A);
        strcpy(A,B);
        strcpy(B,C);
        int c=a;
        a=b;
        b=c;
    }
    for(int i=0;i<a;i++)
    {
        C[i]=A[a-1-i];       
    }
    for(int i=0;i<b;i++)
    {
        D[i]=B[b-1-i];
    }
    for(int i=0;i<a;i++)
    {
        int digitA=C[i]-'0';
        int digitB=(i<b)?D[i]-'0':0;
        int sum=digitA+digitB+car;
        A[i]=(sum%10)+'0';
        car=sum/10;
    }
    if(car)
    {
        A[a++]='1';
        A[a]='\0';
    }
    for(int i=0;i<a;i++)
    {
        B[i]=A[a-1-i];
    }
    B[a]='\0';
    printf("%s",B);
}
int main()
{
    scanf("%s %s",A,B);
    add2(A,B);
}