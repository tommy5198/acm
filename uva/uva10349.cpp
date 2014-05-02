// bimatch
#include<cstdio>
#include<cstring>

int n, m;
int l, r, ttl;
int mat[50][50];
int L[400], R[400];
bool e[400][400];
bool vis[400];
int d[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void dfs1(int x, int y, int p, bool LR){
    for(int i=0; i<4; i++){
        int tx = x+d[i][0], ty = y+d[i][1];
        if(LR && mat[tx][ty] >= 0){
            int tmp = mat[tx][ty];
            if(!tmp)
                mat[tx][ty] = tmp = r++;
            if(!L[p] && !R[tmp])
                L[p] = tmp, R[tmp] = p;
            e[p][tmp] = true;
            dfs1(tx, ty, l, !LR);

        }else if(!LR && !mat[tx][ty]){
            mat[tx][ty] = l++;
            dfs1(tx, ty, l-1, !LR);
        }
    }
}

void init(){
    scanf("%d%d", &n, &m);
    memset(e, false, sizeof(e));
    memset(mat, -1, sizeof(mat));
    memset(L, -1, sizeof(L));
    memset(R, -1, sizeof(R));
    ttl = 0;
    for(int i=1; i<=n; i++){
        getchar();
        for(int j=1; j<=m; j++)
            if(getchar() == '*'){
                mat[i][j] = 0;
                ttl++;
            }
    }
    
    l = r = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(!mat[i][j]){
                mat[i][j] = l++;
                dfs1(i, j, l-1, true);
            }
}

bool dfs(int nw){
    for(int i=1; i<r; i++)
        if(!vis[i] && e[nw][i]){
            vis[i] = true;
            if(R[i]<0 || dfs(R[i])){
                R[i] = nw;
                L[nw] = i;
                return true;
            }
        }
    return false;
}

void sol(){
    int sum = 0;
    for(int i=1; i<l; i++)
        if(L[i]<0){
            memset(vis, false, sizeof(bool)*r);
            if(dfs(i)) sum++;
        }else
            sum++;
    printf("%d\n", ttl-sum);
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
