//dp
#include<cstdio>

int n;
int num[350][350];
int dp[350][350];
void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            scanf("%d", num[i]+j);
}

void sol(){
    for(int i=0; i<n; i++)
        dp[n-1][i] = num[n-1][i];
    for(int i=n-2; i>=0; i--)
        for(int j=0; j<=i; j++)
            dp[i][j] = dp[i+1][j]>dp[i+1][j+1] ? dp[i+1][j]+num[i][j] : dp[i+1][j+1]+num[i][j];
    printf("%d\n", dp[0][0]);
}
int main(){
    init();
    sol();
    return 0;
}
