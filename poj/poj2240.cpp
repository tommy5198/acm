//bellman + detect negative cycle
#include<cstdio>
#include<string>
#include<map>
using namespace std;

struct line{
    int u, v;
    double r;
}e[10001];

int n, m;
double value[30];
map<string, int> mp;

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    mp.clear();
    for(int i=0; i<n; i++){
        char str[101];
        scanf("%s", str);
        mp[string(str)] = i;
        value[i] = 1;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        char a[101], b[101];
        double r;
        scanf("%s%lf%s", a, &e[i].r, b);
        e[i].u = mp[string(a)];
        e[i].v = mp[string(b)];
    }
    return true;
}

bool Relax(int u, int v, double r){
    if(value[u] * r > value[v]){
        value[v] = value[u] * r;
        return true;
    }
    return false;
}

bool sol(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            Relax(e[j].u, e[j].v, e[j].r);
    for(int j=0; j<m; j++)
        if(Relax(e[j].u, e[j].v, e[j].r))
            return true;
    return false;
}

int main(){
    int T = 1;
    while(init()){
        if(sol())
            printf("Case %d: Yes\n", T++);
        else
            printf("Case %d: No\n", T++);
    }
    return 0;
}
