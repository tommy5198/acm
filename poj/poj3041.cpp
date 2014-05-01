#include<cstdio>
#include<cstring>

int n, k;
int r[501], c[501];
bool e[501][501];
bool vis[501];

void init(){
    scanf("%d%d", &n, &k);
    while(k--){
        int a, b;
        scanf("%d%d", &a, &b);
        e[a][b] = true;
        if(!r[a] && !c[b])
            r[a] = b, c[b] = a;
    }
}

bool dfs(int now){
    for(int i=1; i<=n; i++)
        if(!vis[i] && e[now][i]){
            vis[i] = true;
            if(!c[i] || dfs(c[i])){
                r[now] = i;
                c[i] = now;
                return true;
            }
        }
    return false;
}

void sol(){
    int ans = n;
    for(int i=1; i<=n; i++)
        if(!r[i]){
            memset(vis, false, sizeof(bool)*(n+1));
            if(!dfs(i)) ans--;
        }
    printf("%d\n", ans);
}

int main(){
    init();
    sol();
    return 0;
}
