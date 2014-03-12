#include<cstdio>

int n, m;
int r[50001], p[50001];

void init(){
    for(int i=1; i<=n; i++){
        r[i] = 0;
        p[i] = i;
    }
}

int findset(int x){
    return p[x]==x ? x : p[x]=findset(p[x]);
}

void link(int a, int b){
    if(r[a] > r[b])
        p[b] = a;
    else{
        p[a] = b;
        if(r[a] == r[b])
            r[b]++;
    }
    n--;
}

void uni(int a, int b){
    a = findset(a);
    b = findset(b);
    if(a != b) link(a, b);
}

int main(){
    int T = 1;
    while(scanf("%d%d", &n, &m), n||m){
        init();
        for(int i=0; i<m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            uni(a, b);
        }
        //print
        printf("Case %d: %d\n", T++, n);
    }
    return 0;
}
