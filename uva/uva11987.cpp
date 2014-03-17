#include<cstdio>

int p[200001], no[200001], sm[200001];
int st[100001];
int n, m;
bool init(){
    if(scanf("%d%d", &n, &m) == EOF)
        return false;
    for(int i=1; i<=n; i++){
       st[i] = i;
       p[i] = i;
       no[i] = 1;
       sm[i] = i;
    }
    return true;
}

int fd(int x){
    return p[x]==x ? x : p[x]=fd(p[x]);
}

void uni(int a, int b){
    int sa = fd(st[a]), sb = fd(st[b]);
    if(sa != sb){
        no[sb] += no[sa];
        sm[sb] += sm[sa];
        p[sa] = sb;
    }
}

void leave(int x){
    int px = fd(st[x]);
    no[px]--;
    sm[px] -= x;
    st[x] = ++n;
    p[st[x]] = st[x];
    no[st[x]] = 1;
    sm[st[x]] = x;
}
void sol(){
    for(int i=0; i<m; i++){
        int cmd, a, b;
        scanf("%d", &cmd);
        if(cmd <=2){
            scanf("%d%d", &a, &b);
            if(fd(st[a]) == fd(st[b])) continue;
            if(cmd == 2)
                leave(a);
            uni(a, b);
        }else{
            scanf("%d", &a);
            printf("%d %d\n", no[fd(st[a])], sm[fd(st[a])]);
        }
    }
}

int main(){
    while(init())
        sol();
    return 0;
}
