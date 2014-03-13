//MST by kruskal
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Line{
    int a, b;
    int len;
    bool operator<(const Line &t)const{
        return len < t.len;
    }
} tmp;
int n, m;
int f[751];
vector<Line> v;

int fd(int x){
    return f[x]==x ? x : f[x] = fd(f[x]);
}

void uni(int a, int b){
    if(a != b)
        f[a] = b;
}
void init(){
    int p[751][2];
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &p[i][0], &p[i][1]);
        f[i] = i;
    }
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++){
            tmp.len = (p[i][0]-p[j][0])*(p[i][0]-p[j][0]) + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
            tmp.a = i;
            tmp.b = j;
            v.push_back(tmp);
        }
    sort(v.begin(), v.end());
    scanf("%d", &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        uni(fd(a), fd(b));
    }
}

void sol(){
    for(int i=0; i<v.size(); i++){
        int a = fd(v[i].a), b = fd(v[i].b);
        if(a != b){
            printf("%d %d\n", v[i].a, v[i].b);
            uni(a, b);
        }
    }
}
int main(){
    init();
    sol();
    return 0;
}
