#include<cstdio>
#include<algorithm>
int n;
int a[100], p[100];
int sum[100], dp[100];
void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", a+i, p+i);
        sum[i] = i==0 ? a[i] : sum[i-1]+a[i];
    }
}

void sol(){
    int ans = 0;
    dp[0] = (a[0]+10)*p[0];
    for(int i=1; i<n; i++){
        dp[i] = (sum[i]+10)*p[i];
        for(int j=0; j<i; j++)
            dp[i] = std::min(dp[j]+(sum[i]-sum[j]+10)*p[i], dp[i]);
    }
    printf("%d\n", dp[n-1]);
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
