#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 1000000000

int n, p, t;
int cap[201][201];
int flow[201][201];
int len[40000];
int mi, mx, mid;
vector<int> L[201][201];
void init(){
    scanf("%d%d%d", &n, &p, &t);
    memset(cap, 0, sizeof(cap));
    for(int i=0; i<p; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        cap[b][a]++;
        cap[a][b]++;
        len[i] = w;
        L[a][b].push_back(w);
        L[b][a].push_back(w);
    }
    cap[0][1] = t;
    sort(len, len+p);
    mi = 0; mx = p-1;
    mid = (p-1)/2;
}

bool sol(int MX){
    queue<int> q;
    int minf, p[201];
    memset(flow, 0, sizeof(flow));

    while(1){
        int vis[201] = {false};
        q.push(0);
        while(!q.empty()){
            int nw = q.front();
            q.pop();
            for(int nt=1; nt<=n; nt++){
                if(vis[nt]) continue;
                for(int i=0; i<L[nw][nt].size(); i++){
                    if(L[nw][nt][i]>MX) continue;
                    if(cap[nw][nt]-flow[nw][nt] > 0){
                        p[nt] = nw;
                        vis[nt] = true;
                        q.push(nt);
                        break;
                    }else if(flow[nt][nw] > 0){
                        p[nt] = -nw;
                        vis[nt] = true;
                        q.push(nt);
                        break;
                    }
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
    return flow[0][1] == t;
}

int main(){
    init();
    while(mi < mx){
        if(sol(len[mid]))
            mx = mid;
        else
            mi = mid+1;
        mid = (mi + mx)/2;
    }
    printf("%d\n", len[mid]);
    return 0;
}
