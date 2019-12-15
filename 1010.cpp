
#include <stdio.h>
#include <string.h>
#include <math.h>

int pow(int a,int b)
{
    int sum=1;
    if(a==0)
        return 0;
    if(b==0)
    return 1;
    for(int i=0;i<b;i++)
        sum*=a;
    return sum;
}

int binary(char *n2,int left,int right,int sum_1)
{
    int sum_2=0;
    int str2=strlen(n2);
    int radix=(left+right)/2;
    for(i=0;i<str2;i++)
        if(n2[i]>='0'&&n2[i]<='9')
            sum_2+=(n2[i]-'0')*pow(radix,str2-i-1);
        else
            sum_2+=(n2[i]-'a'+10)*pow(radix,str2-i-1);
    if(sum_2<sum_1)
        return binary(n2,radix,right,sum_1);
    else if(sum_2==sum_1)
        return radix;
    else
        return binary(n2,left,radix,sum_1);
        
    if(left==right)
        return left;
}

int main()
{
    char n1[12],n2[12];
    int tag,radix;
    int i;
    int sum_1=0,sum_2=0;
    scanf("%s%s%d%d",n1,n2,&tag,&radix);
    if(tag==2)
    {
        char n[12];
        strcpy(n,n1);
        strcpy(n1,n2);
        strcpy(n2,n);
    }
    int str1=strlen(n1),str2=strlen(n2);
    for(i=0;i<str1;i++)
    {
        if(n1[i]>='0'&&n1[i]<='9')
            sum_1+=(n1[i]-'0')*pow(radix,str1-i-1);
        else
            sum_1+=(n1[i]-'a'+10)*pow(radix,str1-i-1);
    }
    radix=binary(n2,0,9999999999,sum_1);
    for(i=0;i<str2;i++)
        if(n2[i]>='0'&&n2[i]<='9')
            sum_2+=(n2[i]-'0')*pow(radix,str2-i-1);
        else
            sum_2+=(n2[i]-'a'+10)*pow(radix,str2-i-1);
    printf("%d %d %d",sum_1,sum_2,radix);
     /*if(sum_2==sum_1)
        {
            printf("%d",radix);
            break;
        }
        else if(sum_2>sum_1)
        {
            printf("Impossible");
            break;
        }
        else if((sum_2==0&&radix!=0)||(sum_2==1&&radix!=1))
        {
            printf("Impossible");
            break;
        }
        radix++;*/
    return 0;
}
