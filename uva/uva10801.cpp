#include<cstdio>
#define INF 1e9

struct line{
    int u, v, w;
}e[10000];
int n, m, k, mx;
int t[6], flr[1000];
int dis[105];

bool init(){
    if(scanf("%d%d", &n, &k) == EOF)
        return false;
    for(int i=1; i<=n; i++)
        scanf("%d", t+i);
    m = 0;
    mx = 0;
    for(int i=1; i<=n; i++){
        int f;
        char c;
        for(f=0; !f || (c=getchar()) != '\n' && c; f++){
            scanf("%d", flr+f);
            dis[flr[f]] = INF;
            mx = mx>flr[f] ? mx : flr[f];
        }
        dis[k] = INF;
        dis[0] = 0;
        for(int j=1; j<f; j++)
            for(int x=0; x<j; x++){
                int cost = t[i] * (flr[j] - flr[x]) + 60;
                e[m].u = flr[j]; e[m].v = flr[x]; e[m++].w = cost;
                e[m].u = flr[x]; e[m].v = flr[j]; e[m++].w = cost;
            }
    }
    return true;
}

void Relax(int u, int v, int w){
    if(dis[u] + w < dis[v])
        dis[v] = dis[u] + w;
}

void sol(){
    for(int i=0; i<mx-1; i++)
        for(int j=0; j<m; j++)
            Relax(e[j].u, e[j].v, e[j].w);
    if(dis[k] != INF){
        if(dis[k] == 0) dis[k] += 60;
        printf("%d\n", dis[k] - 60);
    }
    else
        puts("IMPOSSIBLE");
}
int main(){
    while(init())
        sol();
    return 0;
}
