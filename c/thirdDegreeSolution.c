#include <stdio.h>
#include <math.h>
typedef struct sol{
    int a;
    int b;
};

int calcu(int a, int b, int c, int x, int time)
{
    if (time==0)
    {
        return x*x*x+a*x*x+b*x+c;
    }
    else if (time ==1)
    {
        
    }

}

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int A[200];
    int j=0;
    struct sol res[3]={0};
    int idx=0;
    for(int i=-c;i<=c;i++)
    {
        if(i==0) continue;
        if(c%i==0)
        {
            A[j++]=i;
        }
    }
    for(int k=0;k<j;k++)
    {
        int d=A[k];
        if(d*d*d+a*d*d+b*d+c==0)
        {
            res[idx].a=d;

        }
    }
}