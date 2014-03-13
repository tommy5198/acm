//disjoint set
#include<cstdio>

int n;
int p[10000];
bool e[10000];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
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
bool uni(int a, int b, bool ise){
    int pa = fd(a), pb = fd(b);
    if(pa == pb)
        return !(ise^e[a]^e[b]);
    else{
        p[pa] = pb;
        e[pa] = ise^e[a]^e[b];
        return true;
    }
}

bool check(int a, int b, bool ise){
    int pa = fd(a), pb = fd(b);
    if(pa == pb)
        return !(ise^e[a]^e[b]);
    else
        return false;
}
void sol(){
    int cmd, a, b;
    while(scanf("%d%d%d", &cmd, &a, &b), cmd||a||b){
        if(cmd <= 2 && !uni(a, b, cmd-1))
            puts("-1");
        else if(cmd >= 3)
            if(check(a, b, cmd-3))
                puts("1");
            else
                puts("0");
    }
}
int main(){
    init();
    sol();
    return 0;
}
