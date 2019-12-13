#include <stdio.h>
#include <iostream>
#include <map>
class poly
{
    public:
    int coe;
    float term;
    poly operator *(const poly a){
        poly res;
        res.coe=a.coe+this->coe;
        res.term=a.term*this->term;
        if(res.term==0)
            res.coe=0;
        return res;
    }
};

std::map<int, float> res;

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
    int num=0;
    for(i=0;i<term1;i++)
    {
        for(j=0;j<term2;j++)
        {
            result[num++]=p1[i]*p2[j];
        }
    }
    
    for(i=0;i<num;i++)
    {
        res[result[i].coe]+=result[i].term;
        if(res[result[i].term]==0)
            res.erase(result[i].term);
    }
    
    printf("%d",res.size());
    for(std::map<int,float>::reverse_iterator t=res.rbegin();t!=res.rend();t++)
    {
            printf(" %d %.1f",t->first,t->second);
    }
    return 0;
}
