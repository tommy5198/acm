#include<cstdio>
#include<algorithm>
int n;
int num[2][21];
int dp[21][21];

void init(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", num[0]+i);
}

void sol(){
    int idx = 1;
    while(scanf("%d", num[1]+idx) != EOF){
        if(idx != n){
            idx++;
            continue;
        }
        idx = 1;
        for(int i=0; i<=n; i++)
            dp[i][0] = dp[0][i] = 0;
        for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if(num[0][i] == num[1][j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
        }
        printf("%d\n", dp[n][n]);
    }
}
int main(){
    init();
    sol();
    return 0;
}
