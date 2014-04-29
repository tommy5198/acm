// DP knap count
#include<cstdio>
#include<cstring>

int n, m;
int a[100], c[100];
bool dp[100001];
int cnt[100001];

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    for(int i=0; i<n; i++)
        scanf("%d", c+i);
    memset(dp, false, sizeof(bool)*(m+1));
    dp[0] = true;
    return true;
}

void sol(){
    int sum = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=m; j++){
            cnt[j] = 0;
            if(j < a[i]) continue;
            if(!dp[j] && dp[j-a[i]] && cnt[j-a[i]] != c[i]){
                sum = sum+1;
                cnt[j] = cnt[j-a[i]] + 1;
                dp[j] = true;
            }
        }
    printf("%d\n", sum);
}

int main(){
    while(init())
        sol();
    return 0;
}
