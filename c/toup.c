#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char c[100];
    while(fgets(c,sizeof(c),stdin))
    {
        for(int i=0;c[i];i++)
        {
            c[i]=toupper(c[i]);
        }
        printf("%s",c);
    }
}