#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 1000000000

int n, m;
int cap[1111][1111];
int flow[1111][1111];

void init(){
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; i++)
        scanf("%d", cap[0]+i);
    for(int i=1; i<=n; i++){
        int a, b, k, prk = 0;
        scanf("%d", &a);
        while(a--){
            scanf("%d", &k);
            cap[k][m+i] = INF;
            if(prk)
                cap[prk][k] = cap[k][prk] = INF;
            prk = k;
        }
        scanf("%d", &b);
        cap[m+i][m+n+1] = b;
    }
}

void sol(){
    int minf, maxf = 0;
    int p[1111];
    queue<int> q;

    while(1){

        bool vis[1111] = {false};
        vis[0] = true;
        q.push(0);

        while(!q.empty()){
            int nw = q.front();
            q.pop();
            for(int nt=1; nt<=n+m+1; nt++){
                if(vis[nt]) continue;
                if(cap[nw][nt] - flow[nw][nt] > 0){
                    vis[nt] = true;
                    p[nt] = nw;
                    q.push(nt);
                }else if(flow[nt][nw] > 0){
                    vis[nt] = true;
                    p[nt] = -nw;
                    q.push(nt);
                }
            }
        }
        if(!vis[m+n+1]) break;
        minf = INF;
        for(int i=m+n+1; i; i=abs(p[i]))
            if(p[i] >= 0)
                minf = min(minf, cap[p[i]][i]-flow[p[i]][i]);
            else
                minf = min(minf, flow[i][-p[i]]);
        for(int i=m+n+1; i; i=abs(p[i]))
            if(p[i] >= 0)
                flow[p[i]][i] += minf;
            else
                flow[i][-p[i]] -= minf;
    }
    for(int i=1; i<=m; i++)
        maxf += flow[0][i];
    printf("%d\n", maxf);
}

int main(){
    init();
    sol();
    return 0;
}
