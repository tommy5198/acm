// bmatch
#include<cstdio>
#include<cstring>

int ans;
int n, m, k;
int A[100], B[100];
bool e[100][100];
bool vis[100];

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    scanf("%d%d", &m, &k);
    ans = 0; 
    for(int i=0; i<n; i++)
        A[i] = -1;
    for(int i=0; i<m; i++)
        B[i] = -1;
    memset(e, false, sizeof(e));
    while(k--){
        int tmp, a, b;
        scanf("%d%d%d", &tmp, &a, &b);
        if(!a||!b) continue;
        e[a][b] = true;
        if(A[a]<0 && B[b]<0){
            A[a] = b; B[b] = a;
            ans++;
        }
    }
    return true;
}

bool dfs(int now){
    for(int i=0; i<m; i++)
        if(!vis[i] && B[i]!=now && e[now][i]){
            vis[i] = true;
            if(B[i]<0 || dfs(B[i])){
                A[now] = i;
                B[i] = now;
                return true;
            }
        }
    return false;
}

void sol(){
    for(int i=0; i<n; i++)
        if(A[i]<0){
            memset(vis, false, sizeof(bool)*m);
            if(dfs(i)) ans++;
        }
    printf("%d\n", ans);
}

int main(){
    while(init())
        sol();
    return 0;
}
