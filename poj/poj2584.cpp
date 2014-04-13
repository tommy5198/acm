// bimatch maxflow by ff
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define INF 100000000

int n;
int flow[30][30];
int cap[30][30];

bool init(){
    char str[11];
    int mp[126];
    mp['S'] = 1; mp['M'] = 2; mp['L'] = 3; mp['X'] = 4; mp['T'] = 5;
    scanf("%s", str);
    if(str[0] == 'E') return false;
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        char a, b;
        getchar();
        a = getchar();
        b = getchar();
        a = mp[a] + n;
        b = mp[b] + n;
        while(a <= b){
            cap[i][b] = 1;
            b--;
        }
        cap[0][i] = 1;
    }
    for(int i=1; i<=5; i++)
        scanf("%d", &cap[i+n][n+6]);
    scanf("%s", str);
    return true;
}

bool sol(){
    
    queue<int> q;
    int p[30], minf;

    while(1){
        bool vis[30] = {false};
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int nw = q.front();
            q.pop();
            for(int i=1; i<=n+6; i++){
                if(vis[i]) continue;
                if(cap[nw][i] - flow[nw][i] > 0){
                    vis[i] = true;
                    p[i] = nw;
                    q.push(i);
                }else if(flow[i][nw] > 0){
                    vis[i] = true;
                    p[i] = -nw;
                    q.push(i);
                }
            }
        }
        if(!vis[n+6]) break;
        minf = INF;
        for(int i=n+6; i; i=abs(p[i]))
            if(p[i]>=0)
                minf = min(minf, cap[p[i]][i] - flow[p[i]][i]);
            else
                minf = min(minf, flow[i][-p[i]]);
        for(int i=n+6; i; i=abs(p[i]))
            if(p[i]>=0)
                flow[p[i]][i] += minf;
            else
                flow[i][-p[i]] -= minf;
    }
    for(int i=1; i<=n; i++)
        if(!flow[0][i])
            return false;
    return true;
}

int main(){
    while(init())
        if(sol())
            puts("T-shirts rock!");
        else
            puts("I'd rather not wear a shirt anyway...");
    return 0;
}
