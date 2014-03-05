#include<cstdio>


struct Edge{
    int u, v, w;
    bool operator<(const Edge &t)const{
        return w<t.w;
    }
}e[100000];
int n, m;
int p[100000];

int findst(int x){
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void uni(int x, int y){
    x = findst(x);
    y = findst(x);
}
int mst(){

}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; i++)
            scanf("%d%d%d", &e[i].u, e[i].v, e[i].w);
        sort(e, e+m);
        printf("%d\n", mst());
    }

}
