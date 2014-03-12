//top sort
#include<cstdio>
#include<vector>
using namespace std;
int n, m;
vector<int> v[1000001];
bool root[1000001];
int vis[1000001];
int ans[1000001];
int p;
void Topsort(int now){
    if(vis[now] == 1) return ;
    vis[now] = 1;

    for(int i=0; i<v[now].size(); i++)
        if(vis[v[now][i]] != 2)
            Topsort(v[now][i]);
    vis[now] = 2;
    ans[--p] = now;
}
void init(){
    for(int i=1; i<=n; i++){
        vis[i] = 0;
        root[i] = true;
        v[i].clear();
    }
    p = n;
}
int main(){
    while(scanf("%d%d", &n, &m), n||m){
        int x, y;
        init();
        while(m--){
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            root[y] = false;
        }
        for(int i=1; i<=n; i++)
            if(root[i])
                Topsort(i);
        if(p)
            printf("IMPOSSIBLE\n");
        else
            for(int i=0; i<n; i++)
                printf("%d\n", ans[i]);
    }
    return 0;
}
