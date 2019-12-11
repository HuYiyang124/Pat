#include <stdio.h>

const char toE[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void reverse(int sum,int end)
{
    if(sum!=0)
    {
        reverse(sum/10,end);
        printf("%s",toE[sum%10]);
        if(sum!=end)
            putchar(' ');
    }
}

int main()
{
    char temp;
    int sum=0;
    while((temp=getchar())!='\n')
    {
        sum+=(temp-'0');
    }
    //printf("%d",sum);
    if(sum==0)
        puts("zero");
    else
        reverse(sum,sum);
    return 0;
}
