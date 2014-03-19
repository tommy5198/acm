#include<cstdio>

int n;
int mx;
int dp[10000], num[10000];
bool init(){
    scanf("%d", &n);
    if(!n) return false;
    for(int i=0; i<n; i++)
        scanf("%d", num + i);
    return true;
}

int sol(){
    mx = 0;
    dp[0] = num[0];
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1]>0 ? dp[i-1]+num[i] : num[i];
        mx = mx>dp[i] ? mx : dp[i];
    }
    return mx;
}

int main(){
    while(init())
        if(sol())
            printf("The maximum winning streak is %d.\n", mx);
        else
            puts("Losing streak.");
    return 0;
}
