// mcmf
#include<cstdio>
#include<cstring>

int n;
int bg[100][100];
int nxt[202], cost[202], inq[202], q[202], p[202];
struct edge{
    int u, v, nt, f, c;
}e[20400];

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    
    memset(nxt, -1, sizeof(int)*(n+n+2));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            scanf("%d", bg[i]+j);
        e[i<<1] = (edge){0, i+1, nxt[0], 1, 0};
        e[i<<1^1] = (edge){i+1, 0, nxt[i+1], 0, 0};
        e[i+n*(n+1)<<1] = (edge){i+n+1, n+n+1, nxt[i+n+1], 1, 0};
        e[i+n*(n+1)<<1^1] = (edge){n+n+1, i+n+1, nxt[n+n+1], 0, 0};
        nxt[0] = i<<1; nxt[i+1] = i<<1^1; 
        nxt[i+n+1] = i+n*(n+1)<<1; nxt[n+n+1] = i+n*(n+1)<<1^1;
    }

    for(int i=0, ecnt=n; i<n; i++)
        for(int j=0, tmp; j<n; j++, ecnt++){
            scanf("%d", &tmp);
            e[ecnt<<1] = (edge){j+1, i+n+1, nxt[j+1], 1, 10000-tmp*bg[j][i]};
            e[ecnt<<1^1] = (edge){i+n+1, j+1, nxt[i+n+1], 0, tmp*bg[j][i]-10000};
            nxt[j+1] = ecnt<<1; nxt[i+n+1] = ecnt<<1^1;
        }
    return true;
}

bool spfa(){
    memset(cost, 1<<6, sizeof(int)*(n+n+2));
    memset(inq, false, sizeof(bool)*(n+n+2));
    q[0] = 0; inq[0] = true; cost[0] = 0; p[0] = -1;
    int qf = 0, qb = 1, nq = 1, ttl = n+n+2;

    while(nq){
        int nw = q[qf%ttl];
        inq[nw] = false;
        qf++, nq--;
        for(int i=nxt[nw]; ~i; i=e[i].nt){
            int nt = e[i].v;
            if(e[i].f > 0 && cost[nw]+e[i].c < cost[nt]){
                cost[nt] = cost[nw] + e[i].c;
                p[nt] = i;
                if(!inq[nt]){
                    inq[nt] = true;
                    q[qb%ttl] = nt;
                    qb++, nq++;
                }
            }
        }
    }
    return cost[n+n+1] & 1<<30;
}

void mcmf(){
    int mc = 0;
    while(!spfa()){
        int ff = 1;
        //for(int i=p[n+n+1]; ~i; i=p[e[i].u])
          //  ff = ff<e[i].f ? ff : e[i].f;

        for(int i=p[n+n+1]; ~i; i=p[e[i].u]){
            e[i].f -= ff;
            e[i^1].f += ff;
        }
    
        mc += ff * (10000 - cost[n+n+1]);
    }
    printf("%d\n", mc);
}

int main(){
    while(init())
        mcmf();
    return 0;
}
