// dp knap
#include<cstdio>

int main()
{
    int n, m;
    int w[3402], v[3402];
    int dp[12881] = {0};
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d%d", w+i, v+i);

    for(int i=0; i<n; i++)
        for(int j=m; j>=w[i]; j--)
            if(j==w[i] || dp[j-w[i]])
                dp[j] = dp[j]>dp[j-w[i]]+v[i] ? dp[j] : dp[j-w[i]]+v[i];
    int ans = 0;
    for(int i=m; i; i--)
        ans = dp[i]>ans ? dp[i] : ans;
    printf("%d\n", ans);
    return 0;
}
