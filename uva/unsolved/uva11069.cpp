//DP
#include<cstdio>

void sol(){
    dp[1][0] = 0;
    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    dp[2][0] = dp[3][0] = 1;
    for(int i=4; i<77; i++){
        dp[i][1] = dp[i-3][1] + dp[i-2][1];
        dp[i][0] = dp[i-1][1];
    }
}
int main(){
    int n;
    int dp[77][2];
    sol();
    while(scanf("%d", &n) != EOF)
        printf("%d\n", dp[n][0] + dp[n][1]);
    return 0;
}
