#include<cstdio>
#define INF 1000000000;
struct line{
    int u, v, w;
}e[2000];
int n, m;
int dis[1000];

void init(){
    scanf("%d%d", &n, &m);
    dis[0] = 0;
    for(int i=1; i<n; i++)
        dis[i] == INF;
    for(int i=0; i<m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
}

bool Relax(int u, int v, int w){
    if(dis[u] + w < dis[v]){
        dis[v] = dis[u] + w;
        return true;
    }
    return false;
}

bool sol(){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<m; j++)
            Relax(e[j].u, e[j].v, e[j].w);
    for(int i=0; i<m; i++)
        if(Relax(e[i].u, e[i].v, e[i].w))
            return true;
    return false;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        if(sol())
            puts("possible");
        else
            puts("not possible");
    }
    return 0;
}
