#include <string.h>
#include <stdio.h>
#define maxx 10000
int size;
int find(int A[],int k)
{
    for(int i=0;i<size;i++)
    {
        if(A[i]==k)
        {
            return i;
        }
    }
    return -1;
}
void addlast(int A[],int d)
{
    int idx=find(A,d);
    if(idx==-1)
    {
        A[size++]=d;
    }
}
void addfirst(int A[],int d)
{
    int idx=find(A,d);
    if(idx==-1)
    {
        for(int i=size;i>0;i--)
        {
            A[i]=A[i-1];
        }
        size++;
        A[0]=d;
    }
}
void addafter(int A[], int k, int v)
{
    int idx=find(A,v);
    if(idx!=-1&&find(A,k)==-1)
    {
        for(int i=size;i>idx+1;i--)
        {
            A[i]=A[i-1];
        }
        A[idx+1]=k;
        size++;
    }
}
void addbefore(int A[], int k, int v)
{
    int idx=find(A,v);
    if(idx!=-1&&find(A,k)==-1)
    {
        for(int i=size;i>=idx;i--)
        {
            A[i]=A[i-1];
        }
        A[idx]=k;
        size++;
    }
}
void removee(int A[],int k)
{
    int idx=find(A,k);
    if(idx!=-1)
    {
        for(int i=idx;i<size-1;i++)
        {
            A[i]=A[i+1];
        }
        size--;
    }
}
void reverse(int A[])
{
    int B[size];
    for(int i=0;i<size;i++)
    {
        B[i]=A[i];
    }
    for(int i=0;i<size;i++)
    {
        A[i]=B[size-1-i];
    }
}
int main()
{
    scanf("%d",&size);
    int A[maxx];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&A[i]);
    }
    char s[30];
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"#")==0) break;
        if(strcmp(s,"addlast")==0)
        {
            int d;
            scanf("%d",&d);
            addlast(A,d);
            for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
        }
        else if(strcmp(s,"addfirst")==0)
        {
            int d;
            scanf("%d",&d);
            addfirst(A,d);
            for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
        }
        else if(strcmp(s,"addafter")==0)
        {
            int k,v;
            scanf("%d %d",&k ,&v);
            addafter(A,k,v);
            for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
        }
        else if(strcmp(s,"addbefore")==0)
        {
            int k,v;
            scanf("%d %d",&k ,&v);
            addbefore(A,k,v);
            for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
        }
        else if(strcmp(s,"remove")==0)
        {
            int d;
            scanf("%d",&d);
            removee(A,d);
            for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
        }
        else if(strcmp(s,"reverse")==0)
        {
            reverse(A);
            for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
}