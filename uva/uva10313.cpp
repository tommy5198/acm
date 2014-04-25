#include<cstdio>

long long dp[301][301];
long long sum[301][301];

void init(){
    dp[0][0] = 1;
    for(int i=1; i<=300; i++)
        for(int j=i; j<=300; j++)
            for(int k=1; k<=j; k++)
                dp[j][k] += dp[j-i][k-1];
    for(int i=1; i<=300; i++)
        for(int j=1; j<=300; j++)
            sum[i][j] = sum[i][j-1] + dp[i][j];
}

int main(){
    int n;
    init();
    while(~scanf("%d", &n)){
        int a = 0, b = n;
        if(getchar() == ' '){
            scanf("%d", &b);
            if(getchar() == ' '){
                a = b;
                scanf("%d", &b);
            }
        }
        if(b > 300) b = 300;
        if(!n && (!b||!a)) puts("1");
        else if(a > b) puts("0");
        else
            printf("%lld\n", sum[n][b]-sum[n][a?a-1:0]);
    }
    return 0;
}
