#include <stdio.h>
#include <iostream>
class poly
{
    public:
    int coe;
    float term;
    poly operator *(const poly a){
        poly res;
        res.coe=a.coe+this->coe;
        res.term=a.term*this->term;
        return res;
    }
};

int main()
{
    int term1, term2;
    scanf("%d",&term1);
    int i,j;
    poly p1[12],p2[12];
    for(i=0;i<term1;i++)
    {
        scanf("%d%f",&p1[i].coe,&p1[i].term);
    }
    scanf("%d",&term2);
    for(i=0;i<term2;i++)
    {
        scanf("%d%f",&p2[i].coe,&p2[i].term);
    }
    i=j=0;
    poly result[105];
    float res[2005]={0};
    int num=0;
    for(i=0;i<term1;i++)
    {
        for(j=0;j<term2;j++)
        {
            result[num++]=p1[i]*p2[j];
        }
    }
    j=0;
    
    for(i=0;i<num;i++)
    {
        if(res[result[i].coe]==0&&result[i].term>0)
            j++;
        res[result[i].coe]+=result[i].term;
    }
    printf("%d",j);
    for(i=2000;i>=0;i--)
    {
        if(res[i]>0)
            printf(" %d %.1f",i,res[i]);
    }
    return 0;
}
