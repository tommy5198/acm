#include<cstdio>
#include<cstring>

int dp[10][156];
int main(){
    int n, k, s;
    while(scanf("%d%d%d", &n, &k, &s), n){
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=k-1; j;j--){
                for(int x=s; x>i; x--){
                    if(dp[j-1][x-i])
                        dp[j][x] += dp[j-1][x-i];
                }
            }
            dp[0][i] = 1;
        }
        printf("%d\n", dp[k-1][s]);
    }
    return 0;
}
