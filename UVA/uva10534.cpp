#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int num[10000];
int dp[2][10000];
int main(){
	
	int n;
	while(scanf("%d",&n)!=EOF){
		int pl=0,pr=0,ans=0;
		vector<int> v[2];
		vector <int> :: iterator itr;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		v[0].push_back(num[0]);
		v[1].push_back(num[n-1]);
		
		for(int i=1;i<n;i++){
			if(v[0][v[0].size()-1] < num[i]){
				v[0].push_back(num[i]);
				dp[0][i] = v[0].size() - 1;
			}else{
				itr = lower_bound(v[0].begin(),v[0].end(),num[i]);
				dp[0][i] = itr - v[0].begin();
				*itr = num[i];
			}if(v[1][v[1].size()-1] < num[n - i - 1]){
				v[1].push_back(num[n - i - 1]);
				dp[1][n - i - 1] = v[1].size() - 1;
			}else{
				itr = lower_bound(v[1].begin(),v[1].end(),num[n - i - 1]);
				dp[1][n - i - 1] = itr - v[1].begin();
				*itr = num[n - i - 1];
			}
		}
		for(int i=0;i<n;i++)
			//printf("%d %d\n",dp[0][i],dp[1][i]);
			ans = max(ans, min(dp[0][i], dp[1][i]));
		printf("%d\n", ans*2+1);
	}
	return 0;
}
