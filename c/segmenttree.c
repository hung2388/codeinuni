#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define maxx 10000
int n;
int A[2*maxx];
int B[maxx];
int max=INT_MIN;
int min=INT_MAX;

void build()
{
    for(int i=n-1;i>0;i--)
    {
        (A[2*i]>A[2*i+1])?(A[i]=A[2*i]):(A[i]=A[2*i+1]);
    }
}
int segmentree(int l,int r)
{
    int res=INT_MIN;
    l+=n; r+=n;
    while(l<=r)
    {
        if(l%2==1){
            if(res<A[l]) res=A[l];
            l++;
        } 
        if(r%2==0)
        {
            if(res<A[r]) res=A[r];
            r--;    
        }
        l/=2;
        r/=2;
    }
    return res;
}
int main()
{
    int sum=0;
    scanf("%d",&n);
    for(int i=n;i<2*n;i++)
    {
        scanf("%d",&A[i]);
        sum+=A[i];
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i]; 
    }
    build();
    while(1)
    {
        char S[30];
        scanf("%s",S);
        if(strcmp(S,"***")==0) break;
        else if(strcmp(S,"*")==0) continue;
        else if(strcmp(S,"find-max")==0)
        {
            printf("%d\n",max);
        }
        else if(strcmp(S,"find-min")==0)
        {
            printf("%d\n",min);
        }
        else if(strcmp(S,"find-max-segment")==0)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",segmentree(a-1,b-1));
        }
        else if(strcmp(S,"sum")==0)
        {
            printf("%d\n",sum);
        }
    }
}