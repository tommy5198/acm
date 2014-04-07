//bellman + detect negative cycle
#include<cstdio>

struct expoint{
    int u, v;
    double r, c;
}e[200];
int n, m, s, k;
double v, value[101];

void init(){
    scanf("%d%d%d%lf", &n, &m, &s, &v);
    for(int i=1; i<=n; i++)
        value[i] = 0.;
    value[s] = v;
    k = 0;
    for(int i=0; i<m; i++){
        scanf("%d%d%lf%lf", &e[k].u, &e[k].v, &e[k].r, &e[k].c);
        k++;
        e[k].u = e[k-1].v;
        e[k].v = e[k-1].u;
        scanf("%lf%lf", &e[k].r, &e[k].c);
        k++;
    }
}

bool Relax(int u, int v, double r, double c){
    if((value[u] - c) * r > value[v]){
        value[v] = (value[u] - c) * r;
        return true;
    }
    return false;
}
bool sol(){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<k; j++)
            Relax(e[j].u, e[j].v, e[j].r, e[j].c);
    for(int i=0; i<k; i++)
        if(Relax(e[i].u, e[i].v, e[i].r, e[i].c))
            return true;
    return false;
}
int main(){
    init();
    if(sol())
        puts("YES");
    else
        puts("NO");
    return 0;
}
