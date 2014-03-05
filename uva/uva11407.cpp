#include<cstdio>
#include<algorithm>
#define INF 100000000

using namespace std;
int dp[10001];

void init(){
	
	for(int i=1;i<10001;i++){
		dp[i] = INF;
	}
	dp[0] = 0;
		
	for(int i=100;i>0;i--){
		for(int j=i*i;j<10001;j++){
			dp[j] = min(dp[j],dp[j-i*i]+1);
		}
	}
}

int main(){
	
	int t,n;
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	
	return 0;
}
