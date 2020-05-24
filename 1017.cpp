#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int stringToInt(string s)
{
	return (atoi(s.substr(0,2).c_str())-8)*60*60 \
	+ atoi(s.substr(3,2).c_str())*60 \
	+ atoi(s.substr(6,2).c_str());
}

struct Info
{
	int atime;
	int stime;
	int ltime;
};

bool cmp(Info &a,Info&b)
{
	return a.atime<b.atime;
}

int main()
{
	int k,n,numCus,waitTime=0,currentWaitCus=0;
	int i,j,id=0;
	string temp;
	Info data[10005];
	int arriveTime,serviceTime;
	scanf("%d%d",&k,&n);
	for(i=0,numCus=k;i<k;i++)
	{
		cin>>temp>>j;
		data[id].atime=stringToInt(temp); 
		data[id].stime=(j>60?60:j)*60;
		if(data[id].atime>32400)
			numCus--;
		else
			id++;
		
	}
	sort(data,data+numCus,cmp);
//	for(i=0;i<numCus;i++)
//		data[i].atime=data[i].atime<0?0:data[i].atime;
	int q[105];
	fill(q,q+n,0);
	id=0;
//	for(i=0;i<numCus;i++)
//		cout<<data[i].atime<<" "<<data[i].stime<<endl;

	for(i=0;i<numCus;i++)
	{
		int fast=q[0],fastid=0;
		for(j=1;j<n;j++)
		{
			if(fast>q[j])
			{
				fast=q[j];
				fastid=j;
			}
		}
		if(q[fastid]<=data[i].atime)
			q[fastid]=data[i].atime+data[i].stime;
		else{
			waitTime+=(q[fastid]-data[i].atime);
			q[fastid]+=data[i].stime;
		}
	}
	
	if(numCus!=0)
	{
		printf("%.1f",(waitTime*1.0)/numCus/60);
	}
	else
		printf("0.0");
	
	
	return 0;	
} 













