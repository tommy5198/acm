#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 1000000
using namespace std;



int main()
{


int v[6]={5,10,20,50,100,200};
int m[6];
    while(scanf("%d%d%d%d%d%d",&m[0],&m[1],&m[2],&m[3],&m[4],&m[5])!=EOF)
	{

        if(!m[0]&&!m[1]&&!m[2]&&!m[3]&&!m[4]&&!m[5])
            break;
        int mx=0;
        for(int i=0;i<6;i++)
            mx+=v[i]*m[i];
        int dp[mx+1];
        int t,tt;
        int tar;
        scanf("%d.%d",&t,&tt);
        tar=t*100+tt;
        int dp2[mx-tar+1];


       for(int i=0;i<mx+1;i++){
           dp[i]=INF;
       }
        for(int i=0;i<mx-tar+1;i++)
            dp2[i]=INF;
        dp[0]=0;
        dp2[0]=0;

        for(int i=0;i<6;i++)
          for(int num=0;num<m[i];num++)
                for(int j=mx;j>=v[i];j--)
                    dp[j]=min(dp[j],dp[j-v[i]]+1);

        for(int i=0;i<6;i++)
            for(int j=v[i];j<mx-tar+1;j++)
                 dp2[j]=min(dp2[j],dp2[j-v[i]]+1);
        int mi=INF;
        int i;
        for(i=0;i<mx-tar+1;i++)
           // if(dp[tar+i]+dp2[i]>0)
           mi=min(dp[tar+i]+dp2[i],mi);

        printf("%3d\n",mi);
	}
	return 0;
}
