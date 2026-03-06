#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define maxx 1000

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int Col[maxx]={0};
        int Row[maxx]={0};
        int cheo1[maxx]={0};
        int cheo2[maxx]={0};
        int a;
        scanf("%d",&a);
        int A[a+1][a+1];
        int res=1;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                if(A[i][j]==1&&Col[j]==0&&Row[i]==0&&cheo1[i+j]==0&&cheo2[i-j+a]==0)
                {
                    Col[j]=1;
                    Row[i]=1;
                    cheo1[i+j]=1;
                    cheo2[i-j+a]=1;
                }
                else if(A[i][j]==0) continue;
                else
                {
                    res=0;
                }
                if(res==0) break;
            }
            if (res==0) break;
        }
        printf("%d\n",res);
    }
}