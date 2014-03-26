#include<cstdio>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;
#define INF 1000000000
struct line{
    int u, v, w;
}e[150];
int n;
int dis[11], vis[11];
int T, idx, x, y;
vector<pair<int, int> > b[11];
vector<int> ans;
bool init(){
    scanf("%d", &n);
    if(!n) return false;
    idx = 0;
    ans.clear();
    for(int i=1; i<=n; i++){
        b[i].clear();
        vis[i] = false;
        dis[i] = INF;
    }
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d", &k);
        while(k--){
            scanf("%d%d", &e[idx].v, &e[idx].w);
            e[idx].u = i;
            b[e[idx].v].push_back(make_pair(i, e[idx].w));
            idx++;
        }
    }
    scanf("%d%d", &x, &y);
    dis[x] = 0;
    return true;
}
void dfs(int now){
    if(now == x)
        return ;
    vis[now] = true;
    for(int i=0; i<b[now].size(); i++)
        if(!vis[b[now][i].first] && dis[now] - dis[b[now][i].first] == b[now][i].second){
            ans.push_back(b[now][i].first);
            dfs(b[now][i].first);
        }
}

void Relax(int u, int v, int w){
    if(dis[u] + w < dis[v])
        dis[v] = dis[u] + w;
}
void sol(){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<idx; j++)
            Relax(e[j].u, e[j].v, e[j].w);
    dfs(y);
    printf("Case %d: Path =", T++);
    for(int i=ans.size()-1; i>=0; i--)
        printf(" %d", ans[i]);
    printf(" %d; %d second delay\n", y, dis[y]);
}
int main(){
    T = 1;
    while(init())
        sol();
    return 0;
}
