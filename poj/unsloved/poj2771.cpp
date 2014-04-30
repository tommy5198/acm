#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int n, l, r;
int h[500];
char sx[500];
char mc[500][101], sp[500][101];
bool e[500][500];
int L[500], R[500], lc[500], rc[500];
bool vis[500];

void dfs1(int now, bool LR){
    if(vis[now]) return;
    vis[now] = true;
    if(LR){
        lc[l] = -1;
        L[l++] = now;
    }else{
        rc[r] = -1;
        R[r++] = now;
    }
    for(int i=0; i<n; i++)
        if(e[now][i])
            dfs1(i, !LR);
}

void init(){
    scanf("%d", &n);
    memset(e, false, sizeof(e));
    for(int i=0; i<n; i++){
        scanf("%d%*c%c%s%s", h+i, sx+i, mc[i], sp[i]);
        for(int j=0; j<i; j++)
            if(abs(h[i]-h[j])<=40 && sx[i]!=sx[j] && !strcmp(mc[i], mc[j]) && strcmp(sp[i], sp[j]))
                e[i][j] = e[j][i] = true;
    }
    memset(vis, false, sizeof(bool)*n);
    l = 0; r = 0;
    for(int i=0; i<n; i++)
        dfs1(i, false);
}

bool dfs(int now){
    for(int i=0; i<r; i++)
        if(!vis[i] && e[L[now]][R[i]]){
            vis[i] = true;
            if(rc[i]<0 || dfs(rc[i])){
                rc[i] = now;
                lc[now] = i;
                return true;
            }
        }
    return false;
}

void sol(){
    int ans = n;
    for(int i=0; i<l; i++)
        if(lc[i]<0){
            memset(vis, false, sizeof(bool)*r);
            if(dfs(i)) ans--;
        }

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
