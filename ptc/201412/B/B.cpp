#include<cstdio>
#include<vector>
using namespace std;

struct node{
    int nt, ct;
};

vector<node> E[101];
int root[101];
int cost[101];
int d[101];

void dfs(int now) {
    
    for(int i=0; i<E[now].size(); i++) {
        int nxt = E[now][i].nt;
        int ct = E[now][i].ct;
        if(ct + d[now] > d[nxt]){
            d[nxt] = ct + d[now];
        }
            dfs(nxt);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int ans = 0, x, y, n, m;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", cost+i);
            E[i].clear();
            root[i] = true;
            d[i] = 0;
        }
        scanf("%d", &m);

        for(int i=0; i<m; i++){
            scanf("%d%d", &x, &y);
         //   E[y].push_back( (node){x, cost[x]});
            d[y][x] = cost[]
            root[x] = false;
        }
        for(int i=1; i<=n; i++)
            if(root[i])
                dfs(i);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                for(int k=1; k<=n; k++)
                    if(d[i][k] + d[k][j] > d[i][j])
                        d[i][j] = d[i][k] + d[k][j];
        for(int i=1; i<=n; i++) {
            if(!E[i].size())
                ans = ans>d[i] ? ans : d[i];
            if(root[i])
                ans += cost[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}


