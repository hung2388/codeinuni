#include <stdio.h>
int A[9][9];
int R[9][10];
int C[9][10];
int B[3][3][10];
int cnt=0;
int check(int i,int j, int k)
{
    if(R[i][k]==1||C[j][k]==1||B[i/3][j/3][k]==1) return 0;
    return 1;
}

void try(int i, int j)
{
    if(i==9)
    {
        cnt++;
        return;
    }
    if(j==9)
    {
        try(i+1,0);
        return;
    }
    if (A[i][j]!=0)
    {
        try(i,j+1);
        return;
    }
    for(int k=1;k<=9;k++)
    {
        if(check(i,j,k))
        {
            A[i][j]=k;
            C[j][k]=1;
            R[i][k]=1;
            B[i/3][j/3][k]=1;
            
            try(i,j+1);

            A[i][j]=0;
            C[j][k]=0;
            R[i][k]=0;
            B[i/3][j/3][k]=0;
        }
    }
}

int main()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&A[i][j]);
            if(A[i][j]!=0)
            {
                C[j][A[i][j]]=1;
                R[i][A[i][j]]=1;
                B[i/3][j/3][A[i][j]]=1;
            }
        }
    }
    try(0,0);
    printf("%d",cnt);
}