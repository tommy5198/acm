#include<cstdio>
#define INF 1e9

int n, m;
int dis[101], nxt[101], p[101], q[101];
bool inq[101];

struct edge{
    int u, v, nt, f, w;
}e[4951];

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    scanf("%d", &m);
    for(int i=0; i<=n; i++)
        nxt[i] = -1;

    for(int i=0; i<m*2; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        e[i<<1] = (edge){a, b, nxt[a], 1, w};
        e[i<<1^1] = (edge){b, a, nxt[b], 0, -w};
        nxt[a] = i<<1; nxt[b] = i<<1^1;
        i++;
        e[i<<1] = (edge){b, a, nxt[b], 1, w};
        e[i<<1^1] = (edge){a, b, nxt[a], 0, -w};
        nxt[b] = i<<1; nxt[a] = i<<1^1;
    }
    e[m*2<<1] = (edge){0, 1, nxt[0], 2, 0};
    nxt[0] = m*2<<1;
    return true;
}

bool spfa(){
    for(int i=0; i<=n; i++){
        dis[i] = INF;
        inq[i] = false;
    }
    q[0] = 0; inq[0] = true; p[0] = -1; dis[0] = 0;
    int qf = 0, qb = 1, nq = 1, ttl = n+1;
    while(nq){
        int nw = q[qf%ttl];
        qf++, nq--;
        inq[nw] = false;
        for(int i=nxt[nw]; ~i; i=e[i].nt){
            int nt = e[i].v;
            if(e[i].f > 0 && dis[nw]+e[i].w < dis[nt]){
                dis[nt] = dis[nw]+e[i].w;
                p[nt] = i;
                if(!inq[nt]){
                    q[qb%ttl] = nt;
                    inq[nt] = true;
                    qb++, nq++;
                }
            }
        }
    }
    return dis[n] != INF;
}

void mcmf(){
    int mc = 0, mf = 0;
    while(spfa()){
        for(int i=p[n]; ~i; i=p[e[i].u]){
            e[i].f--;
            e[i^1].f++;
        }

        mf++;
        mc += dis[n];
    }
    if(mf == 2)
        printf("%d\n", mc);
    else
        puts("Back to jail");
}

int main(){
    while(init())
        mcmf();
    return 0;
}
