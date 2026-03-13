#include <stdio.h>
#include <string.h>
int main()
{
    char s[200];
    char a,b;
    scanf("%s %c %c",s,&a,&b);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==a)
        {
            s[i]=b;
        }
    }
    printf("%s",s);
}