// bimatch
#include<cstdio>
#include<cstring>

int n, m, k;
int l, r;
int mat[34][34];
int L[1200], R[1200];
bool e[1200][1200];
bool vis[1200];
int d[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

void dfs1(int x, int y, int p, bool LR){
    for(int i=0; i<4; i++){
        int tx = x+d[i][0], ty = y+d[i][1];
        if(LR){
            if(!mat[tx][ty]){
                mat[tx][ty] = l++;
                dfs1(tx, ty, l-1, !LR);
            }
        }else{
            if(mat[tx][ty] >= 0){
                int tmp = mat[tx][ty];
                if(!tmp)
                    mat[tx][ty] = tmp = r++;
                e[p][tmp] = true;
                if(!L[p] && !R[tmp])
                    L[p] = tmp, R[tmp] = p;
                dfs1(tx, ty, l, !LR);
            }
        }
    }
}

void init(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<k; i++){
        int ta, tb;
        scanf("%d%d", &ta, &tb);
        mat[tb][ta] = -1;
    }
    if( (n*m-k)%2 ) return ;
    for(int i=0; i<=n+1; i++)
        mat[i][0] = mat[i][m+1] = -1;
    for(int i=0; i<=m+1; i++)
        mat[0][i] = mat[n+1][i] = -1;
    l = r = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(!mat[i][j]){
                mat[i][j] = l++;
                dfs1(i, j, l-1, false);
            }
}

bool dfs(int now){
    for(int i=1; i<r; i++)
        if(!vis[i] && e[now][i]){
            vis[i] = true;
            if(!R[i] || dfs(R[i])){
                L[now] = i;
                R[i] = now;
                return true;
            }
        }
    return false;
}

bool sol(){
    if( (n*m-k)%2 ) return false;
    for(int i=1; i<l; i++)
        if(!L[i]){
            memset(vis, false, sizeof(bool)*r);
            if(!dfs(i)) return false;
        }
    return true;
}

int main(){
    init();
    if(sol())   puts("YES");
    else        puts("NO");
    return 0;
}
