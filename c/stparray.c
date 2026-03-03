#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,c=0;
        scanf("%d %d",&a,&b);
        int A[a],B[b];
        for(int i=0;i<a;i++)
        {
            scanf("%d",&A[i]);
        }
        for(int i=0;i<b;i++)
        {
            scanf("%d",&B[i]);
        }
        if(a!=b)
        {
            printf("0\n");
            continue;
        }
        for(int i=0;i<a;i++)
        {
            if(A[i]!=B[i])
            {
                c=1;
                break;
            }
        }
        if(c==1) printf("0\n");
        else printf("1\n");
    }
}