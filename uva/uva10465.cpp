#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[10000];
int main(){
    int n, m, t;
    while(scanf("%d%d%d", &m, &n, &t) != EOF){
        memset(dp, 0, (t+1)*sizeof(int));
        dp[n] = dp[m] = 1;
        for(int i=min(n, m), j=min(n, m); i<=t; i++)
            if(dp[i-j])
                dp[i] = dp[i]>dp[i-j]+1 ? dp[i] : dp[i-j]+1;
        for(int i=max(n, m), j=max(n, m); i<=t; i++)
            if(dp[i-j])
                dp[i] = dp[i]>dp[i-j]+1 ? dp[i] : dp[i-j]+1;
        if(dp[t])
            printf("%d\n", dp[t]);
        else{
            int tmp = t;
            while(tmp && !dp[--tmp]);
            printf("%d %d\n", dp[tmp], t-tmp);
        }
    }
    return 0;
}

