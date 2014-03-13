//disjoint set
#include<cstdio>

int n, m;
int p[50001], g[50001];

void init(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        p[i] = i;
        g[i] = 0;
    }
}

int fd(int x){
    int grp = 0;
    int pt = x;
    while(p[pt] != pt){
        grp = (grp+g[pt]) % 3;
        pt = p[pt];
    }
    g[x] = grp;
    return p[x] = pt;
}

bool uni(int a, int b, int stat){
    if(a > n || b > n)
        return false;
    int pa = fd(a), pb = fd(b);
    if(pa == pb)
        return (g[a]-g[b]+3)%3 == stat;
    else{
        p[pa] = pb;
        g[pa] = (g[b]-g[a]+stat+3)%3;
        return true;
    }
}

int sol(){
    int lie = 0;
    for(int i=0; i<m; i++){
        int cmd, a, b;
        scanf("%d%d%d", &cmd, &a, &b);
        if(!uni(a, b, cmd-1))
            lie++;
    }
    return lie;
}
int main(){
    init();
    printf("%d\n", sol());
    return 0;
}
