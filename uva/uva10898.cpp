// DP knap
#include<cstdio>
#include<cstring>

int n, k, odr;
int dp[1000000];
int w[14], v[14];

bool init(){
    if(scanf("%d", &n) == EOF)
        return false;
    for(int i=0; i<n; i++){
        w[i] = i ? w[i-1]*10 : 1;
        scanf("%d", v+i);
    }
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        for(int j=0, t = 1; j<n; j++, t*=10){
            int tmp;
            scanf("%d", &tmp);
            w[n+i] = j ? w[n+i]+tmp*t : tmp;
        }
        scanf("%d", v+n+i);
    }
    scanf("%d", &odr);
    return true;
}

void sol(){
    int W, tmp;
    for(int i=0, t=1; i<n; i++, t*=10){
        scanf("%d", &tmp);
        W = i ? W+tmp*t : tmp;
    }
    memset(dp, 1<<6, sizeof(int)*(W+1));
    dp[0] = 0;
    for(int i=0; i<n+k; i++)
        for(int j=w[i]; j<=W; j++)
            dp[j] = dp[j] < dp[j-w[i]]+v[i] ? dp[j] : dp[j-w[i]]+v[i];
    
    printf("%d\n", dp[W]);
}

int main(){
    while(init())
        while(odr--)
            sol();
    return 0;
}
