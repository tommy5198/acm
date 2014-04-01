//Dijkstra + PQ
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9
struct node{
    int id, d;
    bool operator<(const node &tmp)const{
        return d>tmp.d;
    }
};
int n, m, s, t;
int dis[20000];
bool vis[20000];
vector<node> w[20000];
priority_queue<node> pq;
void init(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=0; i<n; i++){
        w[i].clear();
        dis[i] = INF;
        vis[i] = false;
    }
    for(int i=0; i<m; i++){
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        w[a].push_back((node){b, d});
        w[b].push_back((node){a, d});
    }
    while(!pq.empty()) pq.pop();
}

void sol(int T){

    dis[s] = 0;
    pq.push((node){s, dis[s]});

    for(int i=0; i<n; i++){
        int now = -1;
        while(!pq.empty() && vis[now = pq.top().id]) pq.pop();

        if(now == -1) break;
        vis[now] = true;

        for(int j=0; j<w[now].size(); j++){
            node &next = w[now][j];
            if(!vis[next.id] && dis[now] + next.d < dis[next.id]){
                dis[next.id] = dis[now] + next.d;
                pq.push((node){next.id, dis[next.id]});
            }
        }
    }
    if(dis[t] != INF)
        printf("Case #%d: %d\n", T, dis[t]);
    else
        printf("Case #%d: unreachable\n", T);
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        sol(i);
    }
    return 0;
}
