// bimatch
#include<cstdio>
#include<cstring>

int n, m, ttl;
int st[20], cnt[20];
int A[101], B[1000];
bool e[101][1000];
bool vis[1000];

bool init(){
    int tmp, tp;
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;
    ttl = 0;
    for(int i=0; i<n; i++){
        scanf("%d", cnt+i);
        for(int j=ttl; j<cnt[i]+ttl; j++)
            A[j] = -1;
        st[i] = ttl;
        ttl += cnt[i];
    }
    memset(e, false, sizeof(e));
    for(int i=0; i<m; i++){
        scanf("%d", &tmp);
        B[i] = -1;
        while(tmp--){
            scanf("%d", &tp);
            tp--;
            for(int j=st[tp]; j<cnt[tp]+st[tp]; j++){
                e[j][i] = true;
                if(A[j]<0 && B[i]<0)
                    A[j] = i, B[i] = j;
            }
        }
    }
    return true;
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

bool sol(){
    for(int i=0; i<ttl; i++)
        if(A[i] < 0){
            memset(vis, false, sizeof(bool)*m);
            if(!dfs(i))
                return false;
        }
    puts("1");
    for(int i=0; i<n; i++){
        for(int j=st[i]; j<st[i]+cnt[i]; j++){
            if(j != st[i]) printf(" ");
            printf("%d", A[j]+1);
        }
        puts("");
    }
    return true;
}

int main(){
    while(init())
        if(!sol())
            puts("0");
    return 0;
}
