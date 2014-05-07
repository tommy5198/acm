#include<cstdio>
#include<cstring>

int n, m, k;
int v[2000];
bool e[2000][2000];
bool vis[2000];

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;
    k = 0;
    memset(vis, false, sizeof(bool)*n);
    memset(e, false, sizeof(e));
    for(int i=0; i<m; i++){
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        a--; b--;
        e[a][b] = true;
        e[b][a] = p==2;
    }
    return true;
}

void dfs(int nw, bool rev){

    vis[nw] = true;
    for(int i=0; i<n; i++)
        if(!vis[i] && (!rev && e[nw][i] || rev && e[i][nw]) )
            dfs(i, rev);
    v[k++] = nw;
}

bool sol(){
    dfs(0, false);
    if(k != n) return false;
    k = 0;
    memset(vis, false, sizeof(bool)*n);
    dfs(v[n-1], true);
    return k == n;
}

int main(){
    while(init())
        printf("%d\n", sol());
    return 0;
}
