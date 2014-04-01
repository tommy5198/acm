#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 100000
using namespace std;

int n,id;
struct edge
{
	int des,depart,arrival;
};
vector<edge> list[120];
map<string,int> dic;
void SPFA(string A,string B)
{
	int day[120],i,des,depart,arrive,time[120],tmp;
	bool inQ[120];
	queue<int> wait;
	for(i=1;i<=id;i++)
	{
		day[i]=INF;
		inQ[i]=false;
		time[i]=31;
	}
	day[dic[A]]=1;
	wait.push(dic[A]);
	inQ[dic[A]]=true;
	time[dic[A]]=18;//抵達時間
	while(!wait.empty())
	{
		tmp=wait.front();
		inQ[tmp]=false;
		wait.pop();
		for(i=0;i<list[tmp].size();i++)
		{
			des=list[tmp][i].des;
			depart=list[tmp][i].depart;
			arrive=list[tmp][i].arrival;
			//printf("des-%d depart-%d arrive-%d\n",des,depart,arrive);
			if(time[tmp] > depart)//抵達的時間>出發時間
			{
				if(day[tmp]+1 < day[des])
				{
					day[des]=day[tmp]+1;
					time[des]=18;
					if(!inQ[des])
					{
						inQ[des]=true;
						wait.push(des);
					}
				}
			}
			else//抵達時間<=出發時間
			{
				if(day[tmp]<=day[des])
				{
					if(day[tmp]==day[des]  && arrive>time[des])
						continue;
					day[des]=day[tmp];
					time[des]=arrive;
					if(!inQ[des])
					{
						inQ[des]=true;
						wait.push(des);
					}
				}
			}
			//printf("day-%d time-%d\n",day[des],time[des]);

		}
	}
	//printf("%d\n",dic[B]);
	if(day[dic[B]]==INF)
		printf("There is no route Vladimir can take.\n");
	else if(A==B)
		printf("Vladimir needs 0 litre(s) of blood.\n");
	else
		printf("Vladimir needs %d litre(s) of blood.\n",day[dic[B]]);
}
int main()
{
	int test,t,depart,hour,i;
	edge e;
	string name,name2;
    //freopen("t.out", "w", stdout);
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		id=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			cin >> name >> name2 >> depart >> hour;
			if(dic.find(name)==dic.end())
				dic[name]=id++;
			if(dic.find(name2)==dic.end())
				dic[name2]=id++;
			if(depart<=6 && depart>=0)//將早上的時間轉成24加上去的
				depart=24+depart;
			if(depart>=18 && depart+hour <=30)
			{
				e.des=dic[name2];
				e.depart=depart;
				e.arrival=depart+hour;
				list[dic[name]].push_back(e);
			}
		}
		cin >> name >> name2;
		printf("Test Case %d.\n",t);
		SPFA(name,name2);
		dic.clear();
		for(i=1;i<id;i++)
			list[i].clear();
	}
	return 0;
}
