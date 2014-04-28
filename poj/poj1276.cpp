//DP knap count
#include<cstdio>
#include<cstring>

int dp[100001];
int cnt[100001];
int N, n[10], v[10];
int cash;

bool init(){
    if(scanf("%d%d", &cash, &N) == EOF)
        return false;
    memset(dp, 0, (cash+1)*sizeof(int));
    for(int i=0; i<N; i++)
        scanf("%d%d", n+i, v+i);
    return true;
}

void sol(){
    for(int i=0; i<N; i++)
        for(int j=0; j<=cash; j++){
            cnt[j] = 0;
            if(j < v[i]) continue;
            if(dp[j] < dp[j-1]){
                dp[j] = dp[j-1];
                cnt[j] = cnt[j-1];
            }
            if(cnt[j-v[i]] != n[i] && dp[j] < dp[j-v[i]] + v[i]){
                cnt[j] = cnt[j-v[i]] + 1;
                dp[j] = dp[j-v[i]] + v[i];
            }
        }
    printf("%d\n", dp[cash]);
}

int main(){
    while(init())
        sol();
    return 0;
}
