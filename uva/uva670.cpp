// bimatch
#include<cstdio>
#include<cstring>
#include<cmath>

int n, m;
int x[100], y[100];
int mx[100], my[100];
int A[100], B[100];
bool e[100][100];
bool vis[100];


int dis(int a, int b){
    return (mx[a]-x[b])*(mx[a]-x[b])+(my[a]-y[b])*(my[a]-y[b]);
}

int dis1(int a){
    return (x[a]-x[a+1])*(x[a]-x[a+1])+(y[a]-y[a+1])*(y[a]-y[a+1]);
}

void init(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d%d", x+i, y+i);
        A[i] = -1;
    }
    for(int i=0; i<m; i++){
        scanf("%d%d", mx+i, my+i);
        B[i] = -1;
        for(int j=0; j<n-1; j++){
            e[j][i] = sqrt(dis(i, j))+sqrt(dis(i, j+1)) <= 2*sqrt(dis1(j));
            if(e[j][i] && A[j]<0 && B[i]<0)
                A[j] = i, B[i] = j;
        }
    }
}

bool dfs(int nw){
    for(int i=0; i<m; i++)
        if(!vis[i] && e[nw][i]){
            vis[i] = true;
            if(B[i]<0 || dfs(B[i])){
                A[nw] = i;
                B[i] = nw;
                return true;
            }
        }
    return false;
}

void sol(){
    int ans = n+n-1;
    for(int i=0; i<n-1; i++)
        if(A[i]<0){
            memset(vis, false, sizeof(bool)*m);
            if(!dfs(i)) ans--;
        }
    printf("%d\n", ans);
    for(int i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d %d", x[i], y[i]);
        if(A[i] >= 0)
            printf(" %d %d", mx[A[i]], my[A[i]]);
    }
    puts("");
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
