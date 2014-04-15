// max flow by EK
#include<cstdio>
#include<cctype>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 1000000000

int n, m, mx;
int cap[26*28+2][26*28+2];
int flow[26*28+2][26*28+2];
char str[26*26+27][100];

void init(){
    scanf("%d", &n);
    mx = n*n+n+n+2;
    m = n + 1;
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d", &k);
        getchar();
        while(k--){
            int idx = 1;
            str[m][0] = toupper(getchar());
            for(char c=getchar(); c!='\n'&&c!=' '; c=getchar())
                str[m][idx++] = tolower(c);
            if(str[m][0] > 'A'+n-1)
                continue;
            str[m][idx] = 0;
            cap[str[m][0]-'A'+1][m] = 1;
            cap[m][n*n+n+i] = 1;
            m++;
        }
        cap[0][i] = 1;
        cap[n*n+n+i][mx-1] = 1;
    }
}

void sol(int t){
    int minf, p[26*28+2];
    queue<int> q;

    while(1){
        int vis[26*28+2] = {false};
        q.push(0);
        while(!q.empty()){
            int nw = q.front();
            q.pop();
            for(int nt=1; nt<mx; nt++){
                if(vis[nt]) continue;
                if(cap[nw][nt]-flow[nw][nt] > 0){
                    p[nt] = nw;
                    vis[nt] = true;
                    q.push(nt);
                }else if(flow[nt][nw] > 0){
                    p[nt] = -nw;
                    vis[nt] = true;
                    q.push(nt);
                }
            }
        }
        if(!vis[mx-1]) break;
        minf = INF;
        for(int i=mx-1; i; i=abs(p[i]))
            if(p[i] >= 0)
                minf = min(minf, cap[p[i]][i]-flow[p[i]][i]);
            else
                minf = min(minf, flow[i][-p[i]]);
        for(int i=mx-1; i; i=abs(p[i]))
            if(p[i] >= 0)
                flow[p[i]][i] += minf;
            else
                flow[i][-p[i]] -= minf;
    }
    printf("Case #%d:\n", t);
    for(int i=1, j=n+1; i<=n; i++, j=n+1){
        while(!flow[i][j])
            j++;
        puts(str[j]);
    }
        
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
