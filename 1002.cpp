#include <stdio.h>
#include <iostream>
class poly
{
    public:
    int coe;
    float term;
    poly operator+(poly t);
};

poly poly::operator+(poly t)
{
    poly result;
    result.coe = this->coe;
    result.term = t.term+this->term;
    return result;
}

int main()
{
    int term1, term2;
    scanf("%d\n",&term1);
    int i,j;
    poly p1[12],p2[12];
    for(i=0;i<term1;i++)
    {
        scanf("%d%f\n",&p1[i].coe,&p1[i].term);
    }
    scanf("%d\n",&term2);
    for(i=0;i<term2;i++)
    {
        scanf("%d%f\n",&p2[i].coe,&p2[i].term);
    }
    i=j=0;
    poly result[100];
    int num;
    for(num=0;i<term1&&j<term2;num++)
    {
        if(p1[i].coe<p2[j].coe)
        {
            result[num]=p2[j++];
        }
        else if(p1[i].coe>p2[j].coe)
        {
            result[num]=p1[i++];
        }
        else
        {
            result[num]=p1[i++]+p2[j++];
        }
    }
    for(;i<term1;i++)
        result[num++]=p1[i];
    for(;j<term2;j++)
        result[num++]=p2[j];
    
    j=0;
    for(i=0;i<num;i++)
        if(result[i].term!=0)
            j++;
    printf("%d",j);    
    for(i=0;i<num;i++)
        if(result[i].term!=0)
            printf(" %d %.1f",result[i].coe,result[i].term);
    return 0;
}
