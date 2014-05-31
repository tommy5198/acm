// mcmf with spfa 
// imp que by static array
#include<cstdio>
#include<cstring>

#define INF 1e9

struct edge{
    int u, v, nt;
    double f, w;
};

int n, m;
edge e[880];
int nt[42], p[42], q[42], cnt[42];
bool inq[42];
double dis[42];

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;

    double c;
    memset(nt, -1, sizeof(int)*(n+m+2));
    for(int i=0; i<n*m; i++){
        int u = i/m+1, v = i%m+n+1;
        scanf("%lf", &c);
        e[i<<1] = (edge){u, v, nt[u], 1, c};
        e[i<<1^1] = (edge){v, u, nt[v], 0, -c};
        nt[u] = i<<1; nt[v] = i<<1^1;
    }
    for(int i=1; i<=n; i++){
        int ecnt = i-1+(n*m)<<1;
        e[ecnt] = (edge){0, i, nt[0], 1, 0};
        e[ecnt^1] = (edge){i, 0, nt[i], 0, 0};
        nt[0] = ecnt; nt[i] = ecnt^1;
    }

    for(int i=n+1; i<=n+m; i++){
        int ecnt = i-1+(n*m)<<1;
        e[ecnt] = (edge){i, n+m+1, nt[i], 1, 0};
        e[ecnt^1] = (edge){n+m+1, i, nt[n+m+1], 0, 0};
        nt[i] = ecnt; nt[n+m+1] = ecnt^1;
    }
    return true;
}

bool spfa(){
    for(int i=0; i<n+m+2; i++)
        dis[i] = INF;
    memset(inq, false, sizeof(bool)*(n+m+2));
    memset(cnt, 0, sizeof(int)*(n+m+2));
    q[0] = 0; dis[0] = 0; inq[0] = true; p[0] = -1;
    int ttl = n+m+2, qt = 0, qb = 1, nq = 1;
    while(nq){
        int nw = q[qt%ttl];
        inq[nw] = false;
        qt++; nq--;
        for(int i=nt[nw]; ~i; i=e[i].nt){
            int nxt = e[i].v;
            if(e[i].f > 0 && dis[nw]+e[i].w < dis[nxt]){
 //               printf("%d %d\n", nw, nxt);
                dis[nxt] = dis[nw] + e[i].w;
                p[nxt] = i;
                if(!inq[nxt]){
                    q[qb%ttl] = nxt;
                    inq[nxt] = true;
                    cnt[nxt]++;
                    qb++; nq++;
                }
                if(cnt[nxt] == n+m+2)
                    return true;
            }
        }
    }
    return dis[n+m+1] == INF;
}

void mcmf(){ 
    double mf, mc = 0;
    while(!spfa()){
        double ff = INF;
        for(int i=p[n+m+1]; ~i; i=p[e[i].u]){
            ff = ff<e[i].f ? ff : e[i].f;
 //           p[e[i].v] = -1;
 //           printf("%d %d\n", e[i].u, e[i].v);
        }
        for(int i=p[n+m+1]; ~i; i=p[e[i].u]){
            e[i].f -= ff;
            e[i^1].f += ff;
        }
        mf += ff;
        mc += ff * dis[n+m+1];
    }
    char str[1000];
    int tmp;
   // printf("%.2f\n", mc); godamn double
    sprintf(str, "%.0lf", mc*1000/n);
    sscanf(str, "%d", &tmp);
    tmp = tmp%10 >= 5 ? tmp + 5 : tmp;
    printf("%d.%02d\n", tmp/1000, tmp%1000/10);

}

int main(){
    while(init())
        mcmf();
    return 0;
}
