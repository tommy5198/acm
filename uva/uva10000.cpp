#include<cstdio>
#define INF 100000000
struct line{
    int u, v;
}e[10200];
int n, s, T, idx;
int dis[101];

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    scanf("%d", &s);
    for(int i=1; i<=n; i++)
        if(i == s) dis[i] = 0;
        else dis[i] = INF;
    idx = 1;
    while(scanf("%d%d", &e[idx].u, &e[idx].v), e[idx].u||e[idx].v)
        idx++;
    return true;
}

void Relax(int u, int v, int w){
    dis[v] = dis[u] + w < dis[v] ? dis[u] + w : dis[v];
}

void sol(){
    int mi = INF;
    for(int i=0; i<n-1; i++)
        for(int j=0; j<idx; j++)
            Relax(e[j].u, e[j].v, -1);
    for(int i=1; i<=n; i++)
        if(mi > dis[i]){
            mi = dis[i];
            idx = i;
        }

    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", T++, s, -dis[idx], idx);
}
int main(){
    T = 1;
    while(init())
        sol();
    return 0;
}
