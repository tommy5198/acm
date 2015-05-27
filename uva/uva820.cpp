#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
#define MAXN 101
#define INF 10000000
using namespace std;

int dir[MAXN][MAXN], opp[MAX3N][MAXN];
int v;
int max_flow(int source, int target){

    int now, next, minf, p[MAXN], MAX_flow = 0;
    while(1){

        // find augument path
        bool visited[MAXN] = {false};
        queue<int> bfs;
        bfs.push(source);
        visited[source] = true;
        while(!bfs.empty()){
            now = bfs.front();
            for(next = 1; next<=v; next++){
                if(visited[next]) continue;
                if(dir[now][next] - opp[now][next] > 0){
                    p[next] = now;                  // record path
                    visited[next] = true;
                    bfs.push(next);
                }else if(opp[next][now] > 0){       // reverse flow
                    p[next] = -now;                 // record opp path
                    visited[next] = true;
                    bfs.push(next);
                }
            }
            bfs.pop();
        }
        if(!visited[target]) break;                 // cant find aug path
        minf = INF;
        for(int i=target; i!=source; i=abs(p[i])){  // find bottleneck
            if(p[i] >= 0)
                minf = min(minf, dir[p[i]][i]-opp[p[i]][i]);
            else
                minf = min(minf, opp[i][-p[i]]);
        }
        for(int i=target; i!=source; i=abs(p[i])){  // update edge
            if(p[i] >= 0)
                opp[p[i]][i] += minf;
            else
                opp[i][-p[i]] -= minf;
        }
    }
    for(int i=1; i<=v; i++) 
        MAX_flow += opp[source][i];
    return MAX_flow;

}


int main(){

    int count = 1;
    while(scanf("%d", &v), v){
        int s, d, e;
        scanf("%d%d%d", &s, &d, &e);

        
        memset(dir, 0, sizeof(dir));
        memset(opp, 0, sizeof(opp));
        for(int i=0; i<e; i++){
            int t, tt, value;
            scanf("%d%d%d", &t, &tt, &value);
            dir[t][tt] += value;
            dir[tt][t] += value;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", count++, max_flow(s, d));
    }
    return 0;
}
