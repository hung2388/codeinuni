#include <stdio.h>
int A[9][9];
int R[9][10];
int C[9][10];
int Blck[3][3][10];

int main()
{
            R[9][10]={0};
            C[9][10]={0};
    Blck[3][3][10]={0};
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&A[i][j]);
            if(A[i][j]!=0)
            {
                R[i][A[i][j]]==1;
                C[j][A[i][j]]==1;
                
            }
        }
    }
}