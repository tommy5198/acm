#include<cstdio>
#include<algorithm>

int main(){
    int n;
    int ans[7490] = {0};
    int dp[5][7490] = {{0}};
    int v[5] = {1, 5, 10, 25, 50};
    ans[0] = 1;
    for(int i=0; i<5; i++){
        dp[i][0] = 1;
        for(int j=v[i]; j<7490; j++){
            dp[i][j] = i ? j==v[i]?dp[i][j-v[i]]+dp[i-1][j]:dp[i-1][j-v[i]]+dp[i][j-v[i]]+dp[i-1][j] : dp[i][j-v[i]];
            if(j == v[i])
                printf("%d %d %d\n", i, dp[i][j], dp[i][j-v[i]]);
            
            ans[j] = dp[i][j];
        }
    }
    while(scanf("%d", &n) != EOF)   
        printf("%d\n", ans[n]);
    return 0;
}
