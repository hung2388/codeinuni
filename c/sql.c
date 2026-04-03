#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int year, month, day;
} date;

int cmp(const void* p1, const void* p2)
{
    date *x=(date*)p1;
    date *y=(date*)p2;
    if(x->year!=y->year) return x->year-y->year;
    if(x->month!=y->month) return x->month-y->month;
    return x->day-y->day;
}

int main()
{
    date a[2000];
    int n=0;

    while(1)
    {
        char s[20];
        scanf("%s",s);
        if(strcmp(s,"*")==0) break;

        a[n].year=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
        a[n].month=(s[5]-'0')*10+(s[6]-'0');
        a[n].day=(s[8]-'0')*10+(s[9]-'0');
        n++;

        char trash[30];
        scanf("%s%s%s",trash,trash,trash);
    }

    qsort(a,n,sizeof(date),cmp);

    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(i<n && a[i].year==a[i-1].year &&
                  a[i].month==a[i-1].month &&
                  a[i].day==a[i-1].day)
        {
            cnt++;
        }
        else
        {
            printf("%d-%02d-%02d %d\n",
                   a[i-1].year,a[i-1].month,a[i-1].day,cnt);
            cnt=1;
        }
    }
}