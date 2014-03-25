#include<cstdio>

bool init(){
    if(scanf("%d%d", &n, &m) == EOF)
        return false;
    for(int i=0; i<m; i++)
        num[0][i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++)
            scanf("%d", num[i]+j);
        sort(num[i], num[i]+m);
    }
    return true;
}

void sol(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
}
int main(){
    while(init())
        sol();
    return 0;
}
