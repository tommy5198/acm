#include<cstdio>
#include<cmath>

bool vis[10000];
int n, h;
bool dfs(int now, int d){
    if(d == h)
        return false;

    for(int )
}

int main(){
    int T = 1;
    while(scanf("%d%d", &n, &h), n&&h){
        if(h < n || pow(2, h)-1 > n){
            printf("Case %d:", T++);
            continue;
        }
        printf("Case %d:", T++);
        for(int i=1; i<=n ;i++){
            memset(vis, false, sizeof(vis));
            if(dfs(i, 0)){
                //print
                break;
            }
        }
    }
    return 0;
}
