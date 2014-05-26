#include<cstdio>

int n, k, ca;

void init(){
    scanf("%d%d", &n, &k);
}

long long dfs(int num, int bcnt, int ocnt, int zcnt){
    if(!bcnt)
        return num%k ? 0 : 1;
    long long ret = 0;     
    if(zcnt)
        ret += dfs(num, bcnt-1, ocnt, zcnt-1);
    if(ocnt)
        ret += dfs(num|1<<bcnt-1, bcnt-1, ocnt-1, zcnt);
    return ret;
}

void sol(){
    if(n%2)
        printf("Case %d: 0\n", ca++);
    else
        printf("Case %d: %lld\n", ca++, dfs(1<<n-1, n-1, n/2-1, n/2));
}

int main(){
    int T;
    scanf("%d", &T);
    ca = 1;
    while(T--){
        init();
        sol();
    }
    return 0;
}
