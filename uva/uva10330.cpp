#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#define INF 1000000000
using namespace std;

int n;
int cap[202][202];
int flow[202][202];

bool init(){
    int m, d, b, x, y, c;
    if(scanf("%d", &n) == EOF)
        return false;
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    for(int i=1; i<=n; i++)
        scanf("%d", &cap[i][i+n]);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d%d", &x, &y);
        scanf("%d", &cap[x+n][y]);
    }
    scanf("%d%d", &b, &d);
    while(b--){
        scanf("%d", &c);
        cap[0][c] = INF;
    }
    while(d--){
        scanf("%d", &c);
        cap[c+n][2*n+1] = INF;
    }
    return true;
}

void sol(){
    int minf, maxf = 0;
    int p[202];
    while(1){
        bool vis[202] = {false};
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int nt = 1; nt <= 2*n+1; nt++){
                if(vis[nt]) continue;
                if(cap[now][nt] - flow[now][nt] > 0){
                    q.push(nt);
                    p[nt] = now;
                    vis[nt] = true;
                }else if(flow[nt][now] > 0){
                    q.push(nt);
                    p[nt] = -now;
                    vis[nt] = true;
                }
            }
        }
        if(!vis[2*n+1]) break;
        minf = INF;
        for(int i=2*n+1; i; i=abs(p[i])){
            if(p[i]>=0)
                minf = min(minf, cap[p[i]][i]-flow[p[i]][i]);
            else
                minf = min(minf, flow[i][-p[i]]);
        }
        for(int i=2*n+1; i; i=abs(p[i])){
            if(p[i]>=0)
                flow[p[i]][i] += minf;
            else
                flow[i][-p[i]] -= minf;
        }
    }
    for(int i=1; i<=n; i++)
        maxf += flow[0][i];
    printf("%d\n", maxf);
}

int main(){
    while(init())
        sol();
    return 0;
}
