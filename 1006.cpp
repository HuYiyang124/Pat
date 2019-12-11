//exist the locked and unlocked people is same people
//The time is fixed, so this isbig is still effective
/*
int isbig(string a, string b)
{
  for(int i=0;i<a.length();i++)
  {
      if(a[i]>b[i])
          return 1;
      else if(a[i]<b[i])
          return 0;
  }
  return -1;
}
*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> splite(string str, char sign)
{
    vector<string> a;
    int index=0;
    int i;
    for(i=0;i<str.length();i++)
    {
        if(str[i]==sign)
            a.push_back(str.substr(index,i-index));        
    }
    return a;
}

int isbig(string a,string b)
{
    vector<string> s1=splite(a,':');
    vector<string> s2=splite(b,':');
    for(int i=0;i<s1.size();i++)
        if(s1[i]>s2[i])
            return 1;
        else if(s1[i]<s2[i])
            return 0;
    return -1;
}

int main()
{
    string inf[3];
    string max[3],min[3];
    int n;
    scanf("%d",&n);
    max[2]="0:0:0";
    min[1]="24:59:59";
    isbig(max[2],min[1]);
    for(int i=0;i<n;i++)
    {
        cin>>inf[0]>>inf[1]>>inf[2];
        if(isbig(inf[2],max[2])==1||isbig(inf[2],max[2])==-1)
        {
            max[0]=inf[0];
            max[2]=inf[2];
        }
        if(isbig(inf[1],min[1])==0||isbig(inf[1],min[1])==-1)
        {
            min[0]=inf[0];
            min[1]=inf[1];
        }
    } 
    cout<<min[0]<<" "<<max[0];
    return 0;
}
