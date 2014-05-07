// SCC
#include<cstdio>
#include<map>
#include<string>
using namespace std;

int n, m, k;
map<string, int> mp;
int e[1000][1000];
int re[1000][1000];
int ep[1000], rep[1000], stk[1000];
bool vis[1000];

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;

    char a[25], b[25];
    getchar();
    mp.clear();
    for(int i=0; i<n; i++){
        gets(a); 
        mp[string(a)] = i;
        ep[i] = rep[i] = 0;
        vis[i] = false;
    }
    for(int i=0; i<m; i++){
        gets(a);
        gets(b);
        int ta = mp[a], tb = mp[b];
        e[ta][ep[ta]++] = tb;
        re[tb][rep[tb]++] = ta;
    }
    k = 0;
    return true;
}

void dfs(int nw, bool rev){
    int len = rev ? rep[nw] : ep[nw];
    vis[nw] = true;
    for(int i=0; i<len; i++){
        int nt = rev ? re[nw][i] : e[nw][i];
        if(!vis[nt])
            dfs(nt, rev);
    }
    stk[k++] = nw;
}

void sol(){
    int ans = 0;
    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i, false);
    for(int i=0; i<n; i++)
        vis[i] = false;
    for(int i=k-1; i>=0; i--)
        if(!vis[stk[i]]){
            dfs(stk[i], true);
            ans++;
        }
    printf("%d\n", ans);
}

int main(){
    while(init())
        sol();
    return 0;
}
