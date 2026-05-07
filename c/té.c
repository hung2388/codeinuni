#include <stdio.h>
int main()
{
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
for(int i=0;i<4;i++)
{
    for(int j=0;j<2;j++)
    {
        printf("%d ",dir[i][j]);
    
    }
    printf("\n");
}
}