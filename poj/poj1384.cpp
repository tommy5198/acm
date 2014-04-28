//DP knap
#include<cstdio>
#include<algorithm>
#define INF 100000000

int e, f, n;
int p[500], w[500];
int dp[10000];

void init(){
    scanf("%d%d%d", &e, &f, &n);
    for(int i=0; i<n; i++)
        scanf("%d%d", p+i, w+i);
}

void sol(){
    for(int i=1; i<=f-e; i++)
        dp[i] = INF;
    dp[0] = 0;
    for(int i=0; i<n; i++)
        for(int j=w[i]; j<=f-e; j++)
            dp[j] = std::min(dp[j], dp[j-w[i]]+p[i]);
    if(dp[f-e] == INF)
        puts("This is impossible.");
    else
        printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f-e]);
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
