#include <stdio.h>
int main()
{
    int a, b;
    int res=0;
    scanf("%d %d",&a,&b);
    int A[a][b];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int j=0;j<b;j++)
    {
        int check=1;
        for(int i=0;i<a;i++)
        {
            if(A[i][j]==0)
            {
                check=0;
                break;
            }
        }
        if(check==1)
        {
            res++;
        }
    }
    printf("%d",res);
}