// bimatch adj list should be faster
#include<cstdio>
#include<cstring>

int n, m, k;
int R[1001], C[1001];
bool e[1001][1001];
bool vis[1001];
bool Rtag[1001], Ctag[1001];

bool init(){
    scanf("%d%d%d", &n, &m, &k);
    if(!n) return false;
    memset(R, 0, sizeof(int)*(n+1));
    memset(C, 0, sizeof(int)*(m+1));
    memset(e, false, sizeof(e));
    for(int i=0; i<k; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        e[a][b] = true;
        if(!R[a] && !C[b])
            R[a] = b, C[b] = a; 
    }
    return true;
}

bool dfs(int nw){
    Rtag[nw] = true;
    for(int i=1; i<=m; i++)
        if(!vis[i] && e[nw][i]){
            vis[i] = true;
            Ctag[i] = true;
            if(!C[i] || dfs(C[i])){
                C[i] = nw;
                R[nw] = i;
                return true;
            }
        }
    return false;
}

void sol(){
    int sum = n;
    for(int i=1; i<=n; i++)
        if(!R[i]){
            memset(vis, false, sizeof(bool)*(m+1));
            if(!dfs(i)) sum--;
        }
    memset(vis, false, sizeof(bool)*(m+1));
    memset(Rtag, false, sizeof(bool)*(n+1));
    memset(Ctag, false, sizeof(bool)*(m+1));
    for(int i=1; i<=n; i++)
        if(!R[i])
            dfs(i);
    printf("%d", sum);
    for(int i=1; i<=n; i++)
        if(!Rtag[i]) printf(" r%d", i);
    for(int i=1; i<=m; i++)
        if(Ctag[i]) printf(" c%d", i);
    puts("");
}

int main(){
    while(init())
        sol();
    return 0;
}
