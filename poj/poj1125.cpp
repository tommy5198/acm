#include<cstdio>
#define INF 100000000
int n;
int dis[101][101];

bool init(){
    scanf("%d", &n);
    if(!n) return false;

    for(int i=1; i<=n; i++){
        int k;
        scanf("%d", &k);
        for(int j=1; j<=n; j++)
            dis[i][j] = INF;
        while(k--){
            int a, b;
            scanf("%d%d", &a, &b);
            dis[i][a] = b;
        }
    }
    return true;
}


void sol(){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                if(dis[j][i] + dis[i][k] < dis[j][k])
                    dis[j][k] = dis[j][i] + dis[i][k];
    int mi = INF, idx = 0, mx = 0;
    for(int i=1; i<=n; i++){
        int tmp = 0;
        for(int j=1; j<=n; j++)
            if(i != j)
                tmp += dis[i][j];
        if(mi > tmp){
            mi = tmp;
            idx = i;
        }
    }
    printf("%d ", idx);
    for(int i=1; i<=n; i++)
        if(idx != i)
            mx = mx>dis[idx][i] ? mx : dis[idx][i];
    printf("%d\n", mx);
}
int main(){
    while(init())
        sol();
    return 0;
}
