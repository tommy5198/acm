//disjoint set
#include<cstdio>

int n;
int p[100001], r[100001];
void init(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        p[i] = i;
        r[i] = 0;
    }
}

int fd(int x){
    return p[x]==x ? x : p[x]=fd(p[x]);
}

void uni(int a, int b){
    if(a == b) return ;
    if(r[a] > r[b])
        p[b] = a;
    else{
        p[a] = b;
        if(r[a] == r[b])
            r[b]++;
    }
}

void sol(){
    char cmd;
    int a, b, suc = 0, unsuc = 0;
    getchar();
    while(cmd = getchar(), cmd != '\n'&&cmd != EOF){
        scanf("%d%d", &a, &b);
        if(cmd == 'c')
            uni(fd(a), fd(b));
        else if(fd(a) == fd(b))
            suc++;
        else
            unsuc++;
        getchar();
    }
    printf("%d,%d\n", suc, unsuc);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        sol();
        if(T) puts("");
    }
    return 0;
}
