#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000000

int c, s, q, T;
int dis[101][101];

bool init(){
    scanf("%d%d%d", &c, &s, &q);
    if(!c&&!s&&!q) return false;
    for(int i=1; i<=c; i++)
        for(int j=1; j<=c; j++)
            dis[i][j] = INF;
    for(int i=0; i<s; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        dis[a][b] = dis[b][a] = w;
    }
    return true;
}

void sol(){

    for(int k=1; k<=c; k++)
        for(int i=1; i<=c; i++)
            for(int j=1; j<=c; j++)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
    if(T != 1) puts("");
    printf("Case #%d\n", T++);
    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        if(dis[x][y] != INF)
            printf("%d\n", dis[x][y]);
        else
            puts("no path");
    }
}
int main(){
    T = 1;
    while(init())
        sol();
    return 0;
}
