//disjoint set
#include<cstdio>

int n, m;
int p[10000], owe[10000], r[10000];
void init(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &owe[i]);
        p[i] = i;
        r[i] = 0;
    }
}

int fd(int x){
    return p[x]==x ? x : p[x]=fd(p[x]);
}

void uni(int a, int b){
    if(a == b) return ;
    if(r[a] > r[b]){
        p[b] = a;
        owe[a] += owe[b];
    }else{
        p[a] = b;
        owe[b] += owe[a];
        if(r[a] == r[b])
            r[b]++;
    }
}

bool sol(){
    int a, b;
    while(m--){
        scanf("%d%d", &a, &b);
        uni(fd(a), fd(b));
    }
    for(int i=0; i<n; i++)
        if(owe[fd(i)])
            return false;
    return true;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        if(sol())
            puts("POSSIBLE");
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}
