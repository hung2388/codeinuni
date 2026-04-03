#include <stdio.h>
int main()
{
    float num;
    scanf("%f",&num);
    if(num>=0)
    {
        int rl=(int)num;
        printf("%d %.2f",rl,num-rl);
    }
    else
    {
        int rl=(int)num-1;
        printf("%d %.2f",rl,num-rl);
    }
}