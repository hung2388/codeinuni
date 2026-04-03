#include <stdio.h>
#include <string.h>
int main()
{
    char s1[50];
    char s2[50];
    char s3[500];
    char s4[500];
    fgets(s1,sizeof(s1),stdin);
    fgets(s2,sizeof(s2),stdin);
    fgets(s3,sizeof(s3),stdin);
    int sz1=strlen(s1);
    int sz2=strlen(s2);
    int sz3=strlen(s3);
    int i=0;int a=0;
    while(i<sz3)
    {
        if(s3[i]==s1[0]&&s3[i+1]==s1[1])
        {
            int stop=0;
            for(int j=i,k=0;;j++,k++)
            {
                if(s3[j]!=s1[k])
                {
                    stop=j;
                    break;
                }
            }
            i=stop;
            for(int j=0;j<sz2-1;j++)
            {
                s4[a]=s2[j];
                a++;
            }
        }
        else
        {
            s4[a++]=s3[i++];
        }
    }
    s4[a]='\0';
    printf("%s",s4);
}