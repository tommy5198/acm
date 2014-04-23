#include<cstdio>
#include<algorithm>
#include<cstring>

struct Obj{
    int v, w;
    bool operator<(const Obj &t)const{
        return w < t.w;
    }
}obj[1000];

int n, g, mx;
int dp[31];
int mw[100];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &obj[i].v, &obj[i].w);
    std::sort(obj, obj+n);
    scanf("%d", &g);
    mx = 0;
    for(int i=0; i<g; i++){
        scanf("%d", mw+i);
        mx = mx>mw[i] ? mx : mw[i];
    }
    memset(dp, 0, sizeof(dp));
}

void sol(){
    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=mx; j>=obj[i].w; j--)
            dp[j] = std::max(dp[j], dp[j-obj[i].w]+obj[i].v);
    for(int i=0; i<g; i++)
        ans += dp[mw[i]];
    printf("%d\n", ans);
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
