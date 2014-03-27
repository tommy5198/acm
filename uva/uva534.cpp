#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 100000000
struct stone{
    int x, y;
}st[200];
int dis[200][200];
int n;

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    for(int i=0; i<n; i++)
        scanf("%d%d", &st[i].x, &st[i].y);
    for(int i=0; i<n; i++){
        dis[i][i] = INF;
        for(int j=1; j<n; j++)
            dis[i][j] = dis[j][i] = (st[i].x-st[j].x)*(st[i].x-st[j].x)+(st[i].y-st[j].y)*(st[i].y-st[j].y);
    }
    return true;
}

void sol(){
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
    printf("Frog Distance = %.3lf\n\n", sqrt((double)dis[0][1]));
}
int main(){
    for(int i=1; init(); i++){
        printf("Scenario #%d\n", i);
        sol();
    }
    return 0;
}
