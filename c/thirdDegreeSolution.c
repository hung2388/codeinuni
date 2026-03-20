#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    int a;
    int b;
}sol;
int cmp(const void *p1,const void *p2)
{
    sol*x=(sol *)p1;
    sol*y=(sol *)p2;
    if(x->b!=y->b)
        return x->b-y->b;
    else
        return x->a-y->a;
}

int main()
{
    int a,b,c;
    int found=0;
    int ssol=0;
    sol solution[3]={0};
    int k=0;
    scanf("%d %d %d",&a,&b,&c);
    int idx=0;
    int U[1000];
    for(int i=0;i<=abs(c);i++)
    {
        if(c==0)
        {
            U[idx]=0;
            idx++;
            break;
        }
        if(i!=0&&c%i==0)
        {
            U[idx]=i;
            idx++;
            U[idx]=-i;
            idx++;
        }
    }
    for(int i=0;i<idx;i++)
    {
        int x=U[i];
        if(x*x*x+a*x*x+b*x+c==0)
        {
            ssol=x;
            found=1;
            break;
        }
    }
    
    if(found==0)
    {
        printf("NO SOLUTION");
        return 0;
    }
    else
    {
        solution[k].a=ssol;
        solution[k].b++;
        k++;
        int b1=ssol+a;
        int c1=ssol*(ssol+a)+b;
        int delta=b1*b1-4*c1;
        if(delta<0)
        {
            printf("%d %d",solution[0].a,solution[0].b);
            return 0;
        }
        else if(delta==0)
        {
            if(-b1/2==ssol)
            {
                printf("%d 3",solution[0].a);
                return 0;
            }
            else if(b1%2==0)
            {
                solution[1].a=-b1/2;
                solution[1].b=2;
                printf("%d 2\n%d 1",solution[1].a,ssol);
            }
            else
            {
                printf("%d %d",solution[0].a,solution[0].b);
                return 0;
            }
        }
        else
        {
            double x1=(-b1+sqrt(delta))/(2);
            double x2=(-b1-sqrt(delta))/(2);
            if(x1==(int)x1)
            {
                if(x1==ssol)
                {
                    solution[0].b++;
                }
                else
                {
                    solution[k].a=x1;
                    solution[k].b=1;
                    k++;
                }
            }
            if(x2==(int)x2)
            {
                if(x2==ssol)
                {
                    solution[0].b++;
                }
                else
                {
                    solution[k].a=x2;
                    solution[k].b=1;
                    k++;
                }
            }
            qsort(solution,k,sizeof(sol),cmp);
            for(int i=0;i<k;i++)
            {
                printf("%d %d\n",solution[i].a,solution[i].b);
            }
        }
    }
}