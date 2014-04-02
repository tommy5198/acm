#include<cstdio>
#include<vector>
#define INF 1000000000
using namespace std;
struct line{
    int d, l, t;
    line(int a, int b, int c):d(a),l(b),t(c){}
};
int k, n, r;
int dis[101], m[101];
vector<line> e[101], b[101];
bool vis[101];
int mi;
void init(){
    scanf("%d%d%d", &k, &n, &r);
    mi = INF;
    for(int i=1; i<=n; i++)
        dis[i] = i==1 ? 0 : INF;
    int s, d, l, t;
    for(int i=0; i<r; i++){
        scanf("%d%d%d%d", &s, &d, &l, &t);
        e[s].push_back(line(d, l, t));
        b[d].push_back(line(s, l, t));
    }
}

void dfs(int now, int v){
    if(now == 1){
        mi = mi<v ? mi : v;
        return ;
    }
    vis[now] = true;
    for(int i=0; i<b[now].size(); i++)
        if(!vis[b[now][i].d] && b[now][i].l == m[now])
            dfs(b[now][i].d, v+b[now][i].t);
    vis[now] = false;
}

void Relax(int u, int v, int w){
    if(dis[u] + w < dis[v])
        dis[v] = dis[u] + w;
}
void sol(){
    for(int i=0; i<n-1; i++)
        for(int j=1; j<=n; j++)
            for(int x=0; x<e[j].size(); x++)
                Relax(j, e[j][x].d, e[j][x].l);
    for(int i=1; i<=n; i++){
        m[i] = INF;
        for(int j=0; j<b[i].size(); j++)
            m[i] = m[i]<dis[b[i][j].d] ? m[i] : dis[b[i][j].d];
    }
    dfs(n, 0);
    if(mi > k)
        puts("-1");
    else
        printf("%d\n", dis[n]);
}
int main(){
    init();
    sol();
    return 0;
}
