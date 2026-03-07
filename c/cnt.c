#include <stdio.h>
int main()
{
    int i=0;
    char s[200];
    while(scanf("%s",s)==1)
    {
        i++;
    }
    printf("%d",i);
}