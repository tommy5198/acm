#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define INF 1e9

int n, m ,ans;
int cap[520][520];
int flow[520][520];

void init(){
    scanf("%d%d", &n, &m);
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    ans = 0;
    for(int i=0; i<n; i++){
        int t, k, cnt[25] = {0};
        scanf("%d", &k);
        while(k--){
            scanf("%d", &t);
            if(!i && !cnt[t-1]) ans++;
            cnt[t-1]++;
        }
        for(int j=0; j<m; j++){
            if(!cnt[j])
                cap[n*2+2*m*i+j][n+i] = 1;
            else if(cnt[j] > 1)
                cap[i][n*2+2*m*i+m+j] = cnt[j]-1;
            for(int k=0; k<i; k++)
                cap[n*2+2*m*i+m+j][n*2+2*m*k+j] = cap[n*2+2*m*k+m+j][n*2+2*m*i+j] = 1;
        }
        if(i) cap[n+i][i] = INF;
    }
}

void sol(int t){
    int minf, p[520];
    queue<int> q;
    while(1){
        bool vis[520] = {false};
        q.push(0);
        while(!q.empty()){
            int nw = q.front();
            q.pop();
            for(int i=1; i<2*n*(m+1); i++){
                if(vis[i]) continue;
                if(cap[nw][i]-flow[nw][i] > 0){
                    p[i] = nw;
                    vis[i] = true;
                    q.push(i);
                }else if(flow[i][nw] > 0){
                    p[i] = -nw;
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        if(!vis[n]) break;
        minf = INF;
        for(int i=n; i; i=abs(p[i]))
            if(p[i] >= 0)
                minf = min(minf, cap[p[i]][i]-flow[p[i]][i]);
            else
                minf = min(minf, flow[i][-p[i]]);
        for(int i=n; i; i=abs(p[i]))
            if(p[i] >= 0)
                flow[p[i]][i] += minf;
            else
                flow[i][-p[i]] -= minf;
    }
    for(int i=2*n+m; i<2*n+2*m; i++)
        ans += flow[0][i];
    printf("Case #%d: %d\n", t, ans);
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
