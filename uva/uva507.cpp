//DP , FK for 11 WA
#include<cstdio>

int n;
int num[20000], dp[20000];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n-1; i++)
        scanf("%d", num+i);
}

void sol(int T){
    int len = 0, mx = -1, ml = 0;
    int tmp, a, ta, tb, b = 0;
    bool ok = false;
    dp[0] = num[0];
    if(dp[0] >= 0){
        len = 1;
        ta = 0;
        a = 0;
        b = 1;
        ml = 1;
        mx = dp[0];
    }
    for(int i=1; i<n-1; i++){
        dp[i] = dp[i-1]>=0 ? dp[i-1]+num[i] : num[i];
        if(dp[i]>=0){
            if(!len)
                ta = i;
            len++;
        }else
            len = 0;
        if(mx < dp[i] || mx == dp[i] && len > ml){
            b = i+1;
            a = ta;
            ml = len;
            mx = dp[i];
        }
    }
    if(mx <= 0){
        printf("Route %d has no nice parts\n", T);
        return ;
    }
    printf("The nicest part of route %d is between stops %d and %d\n", T, a+1, b+1);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        sol(i);
    }
    return 0;
}
