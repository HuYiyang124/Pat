//when I write the code, I find a intrestion phenomenon.
//the set time is 400ms, when I submit the c and c++, the time last example is 300~400, and sometime timeout.
//but when I submit by clang++, the last examplt is alway timeout.
//so, 1.the clang++ is more slowly than c++. 2.search the address is cost more time, so the struture sometime is not a good choice.
#include <stdio.h>
#include <string.h>

struct city
{
    int num_t;
    int load[505];
}ct[505];

int min_dis=0x3f3f3f3f,max_n=0;
int n, m, c1, c2;
int book[505]={0};
int cot;

void dfs(int x, int num, int dis)
{
    int i;
    if(x==c2)
    {
        if(dis<min_dis)
        {
            max_n=num;
            min_dis=dis;
            cot=1;
        }
        else if(dis==min_dis)
        {
                cot++;
                if(num>max_n)
                    max_n=num;
        }
        return;
    }
    for(i=0;i<n;i++)
    {
        if(book[i]==0&&ct[x].load[i]<0x3f3f3f3f)
        {
            book[i]=1;
            dfs(i, num+ct[i].num_t, dis+ct[x].load[i]);
            book[i]=0;
        }
    }
}

int main()
{
    memset(ct, 0x3f, sizeof(ct));
    scanf("%d %d %d %d\n",&n,&m,&c1,&c2);
    int i,temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        ct[i].num_t = temp;    
    }
    int temp1, temp2;
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d\n",&temp,&temp1,&temp2);
        ct[temp].load[temp1]=temp2;
        ct[temp1].load[temp]=temp2;
    }
    dfs(c1,ct[c1].num_t,0);
    printf("%d %d",cot,max_n);
    return 0;
}
