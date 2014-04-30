// DP
#include<cstdio>
#define INF 1e14

int n, m;
long long dp[301][301];
int x[40], y[40];

void init(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d%d", x+i, y+i);
    for(int i=0; i<=m; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = INF;
}

void sol(){
    long long ans = INF;
    dp[0][0] = 0;
    for(int i=0; i<n; i++)
        for(int j=x[i]; j<=m; j++)
            for(int k=y[i]; k<=m; k++)
                dp[j][k] = dp[j][k]<dp[j-x[i]][k-y[i]] + 1 ? dp[j][k] : dp[j-x[i]][k-y[i]] + 1;
    
    for(int i=0; i<=m ;i++)
        for(int j=0; j<=m; j++)
            if(i*i+j*j == m*m)
                ans = ans<dp[i][j] ? ans : dp[i][j];
    if(ans == INF)
        puts("not possible");
    else
        printf("%lld\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        sol();
    }
    return 0;
}
