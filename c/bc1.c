#include <stdio.h>
int main()
{
    int a;
    int res=0;
    scanf("%d",&a);
    int A[a][a];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int j=0;j<a;j++)
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