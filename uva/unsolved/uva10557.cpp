#include<cstdio>

bool init(){
    scanf("%d", &n);
    if(n == -1) return false;
    m = 0;
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d%d", &eg[i], &k);
        value[i] = -INF;
        while(k--){
            scanf("%d", &e[m].v);
            e[m++].u = i;
        }
    }
    return true;
}

void Relax(int u, int v, int c){
    if(value[u] + c > value[v])
        value[v] = value[u]

}
void sol(){
    for(int i=0; i<n-1; i++)
        for(int i=0; i<m; i++)
            Relax()
}
int main(){
    while(init())
        sol();
    return 0;
}
