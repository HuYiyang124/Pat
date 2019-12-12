#include <stdio.h>

int main()
{
    int n;
    int now,to;
    now=0;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&to);
        //printf("%d\n",sum);
        if(to-now>0)
        {
            sum+=6*(to-now);
        }
        else
            sum+=4*(now-to);
            now=to;
        sum+=5;
    }
    printf("%d",sum);
    return 0;
}
