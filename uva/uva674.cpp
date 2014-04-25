#include<cstdio>
#include<algorithm>

int dp[7490];

int main(){
    int n;
    int c[5] = {1, 5, 10, 25, 50};
    dp[0] = 1;
    for(int i=0; i<5; i++)
        for(int j=c[i]; j<7490; j++)
            dp[j] += dp[j - c[i]];
    while(scanf("%d", &n) != EOF)   
        printf("%d\n", dp[n]);
    return 0;
}
