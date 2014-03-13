//disjoint set
#include<cstdio>

int n, m;
int p[100001];
bool e[100001];

void init(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        p[i] = i;
        e[i] = false;
    }
}

int fd(int x){
    bool ise = false;
    int tx = x;
    while(tx != p[tx]){
        ise ^= e[tx];
        tx = p[tx];
    }
    e[x] = ise;
    return p[x] = tx;
}
void uni(int a, int b){
    int pa = fd(a), pb = fd(b);
    if(pa != pb){
        p[pa] = pb;
        e[pa] = !(e[a]^e[b]);
    }
}

int check(int a, int b){
    int pa = fd(a), pb = fd(b);
    if(pa == pb)
        return e[a]^e[b];
    else
        return -1;
}
void sol(){
    int  a, b;
    char cmd;
    for(int i=0; i<m; i++){
        getchar();
        scanf("%c%d%d", &cmd, &a, &b);
        if(cmd == 'D')
            uni(a, b);
        else if(cmd == 'A'){
            int stat = check(a, b);
            if(stat == 1)
                puts("In different gangs.");
            else if(stat == 0)
                puts("In the same gang.");
            else
                puts("Not sure yet.");
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        sol();
    }
    return 0;
}
