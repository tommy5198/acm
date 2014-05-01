// bimatch
#include<cstdio>
#include<cstring>

int n, m;
int A[500], B[500];
bool e[500][500];
bool vis[500];

void init(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
        B[i] = -1;
    for(int i=0; i<n; i++){
        A[i] = -1;
        for(int j=0; j<m; j++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp){
                e[i][j] = true;
                if(A[i]<0 && B[j]<0)
                    A[i] = j, B[j] = i;
            }else
                e[i][j] = false;
        }
    }
}

bool dfs(int now){
    for(int i=0; i<m; i++)
        if(!vis[i] && e[now][i]){
            vis[i] = true;
            if(B[i]<0 || dfs(B[i])){
                A[now] = i;
                B[i] = now;
                return true;
            }
        }
    return false;
}

void sol(int t){
    int ans = n;
    for(int i=0; i<n; i++)
        if(A[i]<0){
            memset(vis, false, sizeof(bool)*m);
            if(!dfs(i)) ans--;
        }
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", t, ans);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        sol(i);
    }
    return 0;
}
