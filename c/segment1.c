#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define sizee 10000
int max(int a,int b)
{
    return a<b?b:a;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int A[sizee];
int n;
int maxi=INT_MIN;
int mini=INT_MAX;
int sum=0;
void build()
{
    for(int i=n-1;i>0;i--)
    {
        A[i]=max(A[2*i],A[2*i+1]);
    }
}
int seg(int l,int r)
{
    int res=INT_MIN;
    l+=n;
    r+=n;
    while(l<=r)
    {
        if(r%2==0)
        {
            res=max(res,A[r]);
            r--;
        }
        if(l%2==1)
        {
            res=max(res,A[l]);
            l++;
        }
        l/=2;
        r/=2;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i+n]);
        maxi=max(maxi,A[i+n]);
        mini=min(mini,A[i+n]);
        sum+=A[i+n];
    }
    char s[30];
    build();
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"*")==0) continue;
        else if(strcmp(s,"***")==0) break;
        else if(strcmp(s,"find-max")==0)
        {
            printf("%d\n",maxi);
        }
        else if(strcmp(s,"find-min")==0)
        {
            printf("%d\n",mini);
        }
        else if(strcmp(s,"sum")==0)
        {
            printf("%d\n",sum);
        }
        else if(strcmp(s,"find-max-segment")==0)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",seg(a-1,b-1));
        }
    }
}
