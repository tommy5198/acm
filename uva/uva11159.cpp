// bimatch
#include<cstdio>
#include<cstring>

int n, m;
int a[100], b[100];
int A[100], B[100];
bool e[100][100];
bool vis[100];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", a+i);
        A[i] = -1;
    }

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", b+i);
        B[i] = -1;
        for(int j=0; j<n; j++){
            if(a[j] && b[i]%a[j] == 0 || !b[i]){
                e[j][i] = true;
                if(A[j]<0 && B[i]<0)
                    A[j] = i, B[i] = j;
            }else
                e[j][i] = false;
        }
    }
}

bool dfs(int now){
    if(now<0) while(1) ;
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
    printf("Case %d: %d\n", t, ans);
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
