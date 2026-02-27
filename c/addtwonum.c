 #include <stdio.h>
 #include <string.h>
char C[200];
char D[200];
char E[200];
char F[200];
 void addnum(char A[],char B[])
{
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
    int carry=0;
    for(int i=0;i<a;i++)
    {
        D[i]=A[a-1-i];
    }
    for(int i=0;i<b;i++)
    {
        E[i]=B[b-1-i];
    }
    for(int i=0;i<a;i++)
    {
        int digitA=D[i]-'0';
        int digitB=(i<b)?E[i]-'0':0;
        int sum = digitA+digitB+carry;
        F[i]=(sum%10)+'0';
        carry=sum/10;
    }
    if(carry==1)
    {
        F[a]=carry+'0';
        F[a+1]='\0';
    }
    for(int i=0;i<strlen(F);i++)
    {
        D[i]=F[strlen(F)-1-i];
    }
    D[a+1]='\0';
}

 int main()
 {
    char A[20], B[20];
    scanf("%s %s",A,B);
    addnum(A,B);
    printf("%s",D);
 }