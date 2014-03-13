//MST by prim
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

struct Line{
    int a, b;
    double len;
    bool operator<(const Line &t)const{
        return len > t.len;
    }
}line[500][500], tmp;
int n, s;
double p[500][2];

double dis(int a, int b){
    return (p[a][0]-p[b][0])*(p[a][0]-p[b][0]) + (p[a][1]-p[b][1])*(p[a][1]-p[b][1]);
}

void init(){
    scanf("%d%d", &s, &n);
    for(int i=0; i<n; i++)
        scanf("%lf%lf", &p[i][0], &p[i][1]);
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++){
            line[i][j].len = line[j][i].len = dis(i, j);
            line[i][j].a = line[j][i].b = i;
            line[i][j].b = line[j][i].a = j;
        }
}

double sol(){
    priority_queue<Line> pq;
    double ans[500];
    bool vis[500] = {false};
    vis[0] = true;
    for(int i=1; i<n; i++)
        pq.push(line[0][i]);
    for(int cnt=0; cnt<n-1; cnt++){
        while(tmp = pq.top(), vis[tmp.b])
            pq.pop();
        pq.pop();
        vis[tmp.b] = true;
        ans[cnt] = sqrt(tmp.len);
        for(int i=0; i<n; i++)
            if(!vis[i])
                pq.push(line[tmp.b][i]);
    }
    sort(ans, ans+n-1);
    return ans[n-s-1];
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        printf("%.2lf\n", sol());
    }
    return 0;
}
