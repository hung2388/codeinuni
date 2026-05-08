#include <stdio.h>
#include <string.h>
#define maxx 10000
int A[maxx];
int size;
int check(int A[],int k,int size)
{
    for(int i=0;i<size;i++)
    {
        if(A[i]==k)
            return i;
    }
    return -1;
}
void addlast(int A[],int k,int size)
{

}
void addfirst(int A[],int k,int size)
{

}
void addafter(int A[],int k,int v,int size)
{

}
void addbefore(int A[],int k,int v,int size)
{

}
void removee(int A[],int k,int size)
{

}
void reverse(int A[])
{
    int B[size];
    for(int i=0;i<size;i++)
    {
        B[i]=A[size-1-i];
    }
    for(int i=0;i<size;i++)
    {
        A[i]=B[i];
    }
}


int main()
{
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&A[i]);
    }
    char s[30];
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"#")==0)
        {
            break;
        }
        else if(strcmp(s,"addlast")==0)
        {
            int d;
            scanf("%d",&d);
            if(check(A,d,size)==-1)
            {
                A[size]=d;
                size++;
            }
        }
        else if(strcmp(s,"addfirst")==0)
        {
            int k;
            scanf("%d",&k);
            if(check(A,k,size)==-1)
    {
        for(int i=size;i>0;i--)
        {
            A[i]=A[i-1];
        }
        A[0]=k;
        size++;
    }
        }
        else if(strcmp(s,"addafter")==0)
        {
            int k,v;
            scanf("%d %d",&k,&v);
            if(check(A,k,size)==-1&&check(A,v,size)!=-1)
    {
        int f=check(A,v,size);
        for(int i=size;i>f+1;i--)
        {
            A[i]=A[i-1];
        }
        A[f+1]=k;
        size++;
    }

        }
        else if(strcmp(s,"addbefore")==0)
        {
            int k,v;
            scanf("%d %d",&k,&v);
            if(check(A,k,size)==-1&&check(A,v,size)!=-1)
    {
        int f=check(A,v,size);
        for(int i=size;i>f;i--)
        {
            A[i]=A[i-1];
        }
        A[f]=k;
        size++;
    }

        }
        else if(strcmp(s,"remove")==0)
        {
            int k;
            scanf("%d",&k);
            int f=check(A,k,size);
    if(f!=-1)
    {
        for(int i=f;i<size-1;i++)
        {
            A[i]=A[i+1];
        }
        size--;
    }

        }
        else if(strcmp(s,"reverse")==0)
        {
            reverse(A);

        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
}
