#include <stdio.h>
int n;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int col[9][10]={0};
        int row[9][10]={0};
        int square[3][3][10]={0};
        int A[9][9]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
        int check =1;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int c=A[i][j];
                if(c>9||c<1){
                    check=0;
                    break;
                }
                if(col[j][c]==0) col[j][c]=1;
                else {
                    check=0;
                    break;
                }
                if(row[i][c]==0) row[i][c]=1;
                else {
                    check=0;
                    break;
                }
                if(square[i/3][j/3][c]==0) square[i/3][j/3][c]=1;
                else {
                    check=0;
                    break;
                }
            }
            if(check==0) break;
        }
        printf("%d\n",check);
    }
}