// s
#include<cstdio>
#define INF 1000000000

struct line{
    int x, y, w;
}e[5200];
int n, m, w;
int dis[501];
void init(){
    scanf("%d%d%d", &n, &m, &w);
    for(int i=1; i<=n; i++)
        dis[i] = i==1 ? 0 : INF;
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
        e[i+m].x = e[i].y;
        e[i+m].y = e[i].x;
        e[i+m].w = e[i].w;
    }
    for(int i=0; i<w; i++){
        scanf("%d%d%d", &e[i+m*2].x, &e[i+m*2].y, &e[i+m*2].w);
        e[i+m*2].w = -e[i+m*2].w;
    }
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
        for(int j=0; j<m*2+w; j++)
            Relax(e[j].x, e[j].y, e[j].w);
    for(int j=0; j<m*2+w; j++)
        if(Relax(e[j].x, e[j].y, e[j].w))
            return false;
    return true;
}
int main(){
    int F;
    scanf("%d", &F);
    while(F--){
        init();
        if(!sol())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
