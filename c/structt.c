#include <stdio.h>
#include <string.h>
typedef struct timme{
    int y,m,d,h,m,s;
    int count;
    char name[20];
    char q[20];
};
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
    struct timme A[200]={0};
    int idx=0;
    while(1)
    {
        char s[20];
        scanf("%s",s);
        if(strcmp(s,"*")==0)
        {
            break;
        }
        else
        {
            A[idx].y=s[0]*1000+s[1]*100+s[2]*10+s[3];
            A[idx].m=s[5]*10+s[6];
            A[idx].d=s[8]*10+s[9];
            scanf("%s",s);
            A[idx].h=s[0]*10+s[1];
            A[idx].m=s[3]*10+s[4];
            A[idx].s=s[6]*10+s[7];
            scanf("%s",s);
            for(int i=0;i<strlen(s);i++)
            {
                A[idx].name[i]=s[i];
            }
            A[idx].name[strlen(s)]='\0';
            scanf("%s",s);
            for(int i=0;i<strlen(s);i++)
            {
                A[idx].q[i]=s[i];
            }
            A[idx].q[strlen(s)]='\0';
            A[idx].count++;
            idx++;
        }
    }

}