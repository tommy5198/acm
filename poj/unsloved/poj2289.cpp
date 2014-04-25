#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define INF 100000000

int n, m;
int cap[1510][1510];
int flow[1510][1510];

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;
    for(int i=1; i<=n; i++){
        char str[16];
        int a;
        scanf("%s", str);
        for(char c=getchar(); c==' '; c=getchar()){
            scanf("%d", &a);
            cap[i][n+a+1] = 1;
        }
        cap[0][i] = 1;
    }
    return true;
}

void sol(){
    int up = n, low = 1;
    int minf, p[1510];
    queue<int> q;
    while(up != low){
        for(int i=n+1; i<=n+m; i++)
            cap[i][n+m+1] = (up+low)/2;
        memset(flow, 0, sizeof(flow));
        while(1){
            q.push(0);
            bool vis[1510] = {false};
            while(!q.empty()){
                int nw = q.front();
                q.pop();
                for(int i=1; i<=n+m+1; i++){
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
            if(!vis[n+m+1]) break;
            minf = INF;
            for(int i=n+m+1; i; i=abs(p[i]))
                if(p[i] >= 0)
                    minf = min(minf, cap[p[i]][i]-flow[p[i]][i]);
                else
                    minf = min(minf, flow[i][-p[i]]);
            for(int i=n+m+1; i; i=abs(p[i]))
                if(p[i] >= 0)
                    flow[p[i]][i] += minf;
                else
                    flow[i][-p[i]] -= minf;
        }
        bool work = true;
        for(int i=1; i<=n; i++)
            if(!flow[0][i]){
                work = false;
                break;
            }
        if(work)
            up = (up+low)/2;
        else
            low = (up+low)/2 + 1;
    }
    printf("%d\n", up);
}

int main(){
    while(init())
        sol();
    return 0;
}
