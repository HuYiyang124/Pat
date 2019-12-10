#include <stdio.h>
#include <vector>
#include <queue>

#define N 105
using namespace std;

vector<int>a[N];
int result[N];

class node
{
public:
    int level,id;
    node(int x, int y):level(x),id(y){}
};

int main()
{
    int n,m,id,k,x;
    scanf("%d%d\n",&n,&m);
    int i,j;
    for(i = 0; i < m; i++) {
        scanf("%d%d",&id,&k);
        for(j = 0; j < k; j++) 
        {
             scanf("%d ",&x) ; 
             a[id].push_back(x); 
         }
    }   
 
    queue<node> Q;
    Q.push(node(0,1));
    int max_l=0;
    while(!Q.empty()){
        node x=Q.front();
        Q.pop();
        max_l=max(max_l, x.level);
        if(a[x.id].size()==0)
            result[x.level]++;
        for(i=0;i<a[x.id].size();i++)
        {
            Q.push(node(x.level+1,a[x.id][i]));
        }
    }
    printf("%d",result[0]);
    for(i=1;i<=max_l;i++)
        printf(" %d",result[i]);
    
    return 0;
}

