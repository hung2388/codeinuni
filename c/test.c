#include <stdio.h>
#include <math.h>
int A[2000];
int B[2000];
void merge(int A[],int l,int m, int r)
{
    int l1=l,l2=m+1,r1=m,r2=r,idx=l;
    while(l1<=r1&&l2<=r2)
    {
        if(A[l1]<=A[l2])
        {
            B[idx++]=A[l1++];
        }
        else
        {
            B[idx++]=A[l2++];
        }
    }
    while(l1<=r1)
    {
        B[idx++]=A[l1++];
    }
    while(l2<=r2)
    {
        B[idx++]=A[l2++];
    }
    idx=l;
    while(idx<=r)
    {
        A[idx]=B[idx++];
    }
}
void mergesort(int A[],int l, int r)
{
    if(l>=r) return;
    int m=(l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m+1,r);
    merge(A,l,m,r);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    mergesort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}