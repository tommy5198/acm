#include<cstdio>

int p[100001], nt[100001], sn[100001];

bool init(){
    if(scanf("%d%d", &n, &m) == EOF)
        return false;
    for(int i=1; i<=n; i++){
       p[i] = i;
       nt[i] = i;
       sn[i] = 1;
    }
    return true;
}

void uni(int a, int b){
    sn[b] += sn[a];
    nt[p[b]] = a;
    nt[ed[p[a]]] = b;
    nt[p[a]] = ed[p[a]] = sn[p[a]] = 0;

}
void sol(){
    for(int i=0; i<m; i++){
        int cmd, a, b;
        scanf("%d", &cmd);
        if(cmd <=2){
            scanf("%d%d", &a, &b);
            if(p[a] == p[b]) continue;
            if(cmd == 2)
                leave(a);
            uni(a, b);
        }else{
            scanf("%d", &a);
            printf("%d\n", sn[p[a]]);
        }
    }
}

int main(){
    while(init())
        sol();
    return 0;
}
