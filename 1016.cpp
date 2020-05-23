#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <cstdlib>

using namespace std;

int totalTime;
bool isBig(string s1, string s2)
{
	int m=min(s1.size(),s2.size());
	if(s1[0]>='a' && s2[0]>='A' &&s2[0]<='Z'&&'z'>=s1[0])
		return 0;
	else if(s2[0]>='a' && s1[0]>='A' &&s1[0]<='Z'&&'z'>=s2[0])
		return 1;
	else
		return s1>s2;
}

class Info
{
public:
	string name;
	string time;
	string sta;
	bool operator <(const Info & info)const{
		if(name==info.name)
		{
			return time<info.time;
		}
		else
			return name<info.name;
	}
	
};

int calculateMoney(int *money,string s1, string s2)
{
	totalTime=0;
	int res=0;
	int d1,h1,m1,d2,h2,m2;
	d1=atoi(s1.substr(0,2).c_str());
	d2=atoi(s2.substr(0,2).c_str());
	h1=atoi(s1.substr(3,2).c_str());
	h2=atoi(s2.substr(3,2).c_str());
	m1=atoi(s1.substr(6,2).c_str());
	m2=atoi(s2.substr(6,2).c_str());
	
	while(d1!=d2||h1!=h2||m1!=m2)
	{
		m1++;
		totalTime++;
		res+=money[h1];
		if(m1==60)
		{
			m1=0;h1++;
		}
		if(h1==24)
		{
			h1=0;d1++;
		}
	}
	return res;
}

int main()
{
	multiset<Info> data;
	multiset<Info>::iterator it,start,end,t,pret;
	int money[24];
	int i,n;
	for(i=0;i<24;i++)
		scanf("%d",money+i);
	scanf("%d",&n);
	Info temp;
	for(i=0;i<n;i++)
	{
		cin>>temp.name>>temp.time>>temp.sta;
		data.insert(temp);
	}
	/*for(it=data.begin();it!=data.end();it++)
	{
		cout<<it->name<<" "<<it->time<<" "<<it->sta<<endl;;
	}*/
	string currentName;
	for(it=data.begin();it!=data.end();)
	{
		float currentMoney=0, totalMoney=0;
		int time=0;
		currentName=it->name;
		start=it;
		while(currentName==it->name)
		{
			it++;	
			if(it==data.end())
				break;	
		}
		end=it;
		bool flag=0;
		for(t=start,pret=t++;t!=end;t++,pret++)
		{
			if(pret->sta=="on-line"&&t!=end&&t->sta=="off-line")
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
			cout<<start->name<<" "<<start->time.substr(0,2)<<endl;
		for(t=start,pret=t++;t!=end;t++,pret++)
		{
			if(pret->sta=="on-line"&&t!=end&&t->sta=="off-line")
			{
				string s1,s2;
				s1=pret->time.substr(3,8);
				s2=t->time.substr(3,8);
				currentMoney=calculateMoney(money,s1,s2);
				totalMoney+=currentMoney;
				cout<<s1<<" "<<s2<<" "<<totalTime<<" $";
				printf("%.2f\n",currentMoney/100);
			}
		}
		if(flag==1)
			printf("Total amount: $%.2f\n",totalMoney/100);
		
	}

	return 0;	
	
}





