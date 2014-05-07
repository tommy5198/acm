// cut vectex
#include<cstdio>
#include<vector>
using namespace std;

int n, m;
vector<int> e[10000];
int dfn[10000], low[10000];
int mxcut, dpt;

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;
    for(int i=0; i<n; i++){
        dfn[i] = low[i] = 0;
        e[i].clear();
    }
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dpt = mxcut = 0;
    return true;
}

void dfs(int nw, int p){
    int kid = 0, cut = 0;
    if(p < 0) cut = -1;
    dfn[nw] = low[nw] = ++dpt;
    for(int i=0; i<e[nw].size(); i++){
        int nxt = e[nw][i];
        if(!dfn[nxt]){
            dfs(nxt, nw);
            kid++;
            if(dfn[nw]<=low[nxt]) cut++;
            low[nw] = low[nw]<low[nxt] ? low[nw] : low[nxt];
        }else if(nxt != p)
            low[nw] = low[nw]<dfn[nxt] ? low[nw] : dfn[nxt];
    }
    if(kid>1 || p!=-1)
        mxcut = mxcut<cut ? cut : mxcut;
}

void sol(){
    int ans = 0;
    for(int i=0; i<n; i++)
        if(!dfn[i]){
            dfs(i, -1);
            ans++;
        }
    ans = ans==n ? ans-1 : ans+mxcut;
    printf("%d\n", ans);
}

int main(){
    while(init())
        sol();
    return 0;
}
