// mcmf with spfa
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

#define INF 1<<30
#define MAX 101
#define MAXm 20001

struct edge{
    int u, v, nt, f, w;
};

int n, m, k, d;
queue<int> q;
bool inq[MAX];
int cnt[MAX],  p[MAX], pre[MAX];
int dis[MAX];
edge e[MAXm];

bool spfa(){
    memset(inq, false, sizeof(bool)*(n+1));
    memset(cnt, 0, sizeof(int)*(n+1));
    memset(dis, 1<<6, sizeof(int)*(n+1));
    q.push(0);
    cnt[0] = 1; inq[0] = true; dis[0] = 0; p[0] = -1;
    while(!q.empty()){
        int nw = q.front();
        q.pop();
        inq[nw] = false;
        for(int nte = pre[nw]; ~nte; nte=e[nte].nt){
            edge &edg = e[nte];
            int nt = edg.v;
          //  if(e[p[nw]].u == nt) continue;
            if(edg.f > 0 && dis[nw]+edg.w < dis[nt]){
 //               printf("%d %d\n", nw, nt);
                dis[nt] = dis[nw] + edg.w;
                p[nt] = nte;
                if(!inq[nt]){
                    inq[nt] = true;
                    q.push(nt);
                    cnt[nt]++;
                }
                if(cnt[nt] == n)
                    return true;
            }

        }
    }
    return dis[n] & INF;
}

void MCMF(){
    int mf = 0;
    long long mc = 0;
    while(!spfa()){
        int ff = INF;
        for(int i=p[n]; ~i; i=p[e[i].u])
            ff = ff<e[i].f ? ff : e[i].f;
               
        for(int i=p[n]; ~i; i=p[e[i].u]){
            e[i].f -= ff;
            e[i^1].f += ff;
        }
        
        mf += ff;
        mc += (long long)ff * dis[n];
    }
    if(mf == d)
        printf("%lld\n", mc);
    else
        puts("Impossible.");
}

bool init(){
    if(scanf("%d%d", &n, &m) == EOF)
        return false;
    int a, b, w;
    memset(pre, -1, sizeof(int)*(n+1));
    for(int i=0; i<m*2; i++){
        scanf("%d%d%d", &a, &b, &w);
        e[i<<1] = (edge){a, b, pre[a], 0, w};
        e[i<<1^1] = (edge){b, a, pre[b], 0, -w};
        pre[a] = i<<1; pre[b] = i<<1^1;
        i++;
        e[i<<1] = (edge){b, a, pre[b], 0, w};
        e[i<<1^1] = (edge){a, b, pre[a], 0, -w};
        pre[a] = i<<1^1; pre[b] = i<<1;
    }
    scanf("%d%d", &d, &k);
    for(int i=0; i<m*2; i++)
        e[i<<1].f = k;
    e[m<<2] = (edge){0, 1, -1, d, 0};
    pre[0] = m<<2;
    return true;
}

int main(){
    while(init())
        MCMF();
    return 0;
}
