//MST by prim
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

struct Line{
    int a, b;
    int len;
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
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            scanf("%d", &line[i][j].len);
            line[i][j].a = i;
            line[i][j].b = j;
        }
}

int sol(){
    priority_queue<Line> pq;
    int ans = -1;
    bool vis[500] = {false};
    vis[0] = true;
    for(int i=1; i<n; i++)
        pq.push(line[0][i]);
    for(int cnt=0; cnt<n-1; cnt++){
        while(tmp = pq.top(), vis[tmp.b])
            pq.pop();
        pq.pop();
        vis[tmp.b] = true;
        ans = ans>tmp.len ? ans : tmp.len;
        for(int i=0; i<n; i++)
            if(!vis[i])
                pq.push(line[tmp.b][i]);
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        printf("%d\n", sol());
    }
    return 0;
}
