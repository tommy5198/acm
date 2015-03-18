#include<cstdio>

int main()
{
    int T;
    int a[10000];
    int dp[10000];
    int p[10000];
    int ans[10000];
    scanf("%d", &T);
    getchar(); getchar();
    while(T--) {
        int mx = 0, MX = 0, end = -1;
        char c;
        while((c=getchar()) != '\n' && ~c) {
            a[mx] = 0;
            while(c != '\n') {
                a[mx] = a[mx]*10 + c - '0';
                c = getchar();
            }
            mx++;
        }
        for(int i=0; i<mx; i++) {
            dp[i] = 1, p[i] = -1;
            for(int j=i-1; ~j; j--)
                if(a[j] < a[i] && dp[i] <= dp[j])
                    dp[i] = dp[j] + 1, p[i] = j;
            if(dp[i] > MX)
                MX = dp[i], end = i;
        }
        for(mx = 0; ~end; end = p[end],mx++)
            ans[mx] = a[end];
        printf("Max hits: %d\n", mx);
        while(mx)
            printf("%d\n", ans[--mx]);
        if(T) puts("");
    }
    return 0;
}
