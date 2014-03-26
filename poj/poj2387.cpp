#include<cstdio>
#define INF 1000000000

struct line{
    int x, y, w;
}e[2000];
int dis[1001];
int T, n;
void init(){
    scanf("%d%d", &T, &n);
    for(int i=0; i<T; i++)
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
    for(int i=1; i<=n; i++)
        dis[i] = i==n ? 0 : INF;
}

void Relax(int u, int v, int w){
    if(dis[u]+w < dis[v])
        dis[v] = dis[u]+w;
}
void sol(){
    for(int i=1; i<n; i++)
        for(int j=0; j<T; j++){
            Relax(e[j].x, e[j].y, e[j].w);
            Relax(e[j].y, e[j].x, e[j].w);
        }
    printf("%d\n", dis[1]);
}
int main(){
    init();
    sol();
    return 0;
}
