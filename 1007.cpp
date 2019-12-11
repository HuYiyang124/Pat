#include <stdio.h>
#include <vector>

int main()
{
    int n,temp;
    int first,last;
    int sum=0,max_sum=-0x3f3f;
    int start,end;
    int ms,me;
    int flag=1;
    int len=0,max_len=-1;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        sum+=temp;
        
        if(i==0)
        {
            first=temp;
            start=temp;
        }
        else if(i==n-1)
            last=temp;
        //update the max sum
        if(sum>max_sum)
        {
            max_sum=sum;      
            end=temp;
        }
        if(max_len<len)
        {
            ms=start;
            me=end;
            max_len=len;
        }
        //if the sum less than 0, restart the calculate
        if(flag)
            start=temp;
        
        if(sum<0)
        {
            flag=1;
            sum=0;
            len=0;
        }
        else         
        {
            flag=0;
            len++;
        }
    }
    if(max_sum<0)
        printf("0 %d %d",first,last);
    else
        printf("%d %d %d",max_sum,ms,me);
    return 0;
}
