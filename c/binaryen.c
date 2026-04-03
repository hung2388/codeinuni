#include <stdio.h>
int n;
void try(int n)
{
    if(n==0)
    return;
    int a=n/2;
    int b=n%2;
    try(a);
    printf("%d",b);
}

int main()
{
    scanf("%d",&n);
    try(n);
}