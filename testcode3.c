#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100];
    int i,j,n=0,temp;
    gets(str1);
    for(i=0;str1[i]!='\0';i++)
    {
        n++;
    }
    for(i=0;i<n;i++)
    {
        if(str1[i]>=65 && str1[i]<=90)
        {
            str1[i]=str1[i]+32;
        }
    }
    puts(str1);
    return 0;
}