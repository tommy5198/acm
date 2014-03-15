//2nd MST for template(?
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Line{
    int a, b;
    int len;
    bool operator<(const Line &t)const{
        return len < t.len;
    }
} tmp;
int delta;
bool vis[101], ok;
int n, m, MST;
int L[101][101];
int p[101], r[101];
vector<Line> v, v1, v2;
void init(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        //init
        p[i] = i;
        r[i] = 0;
        for(int j = 0; j<=n; j++)
            L[i][j] = 0;
    }
    MST = 0;
    v.clear();
    v2.clear();
    while(m--){
        scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.len);
        L[tmp.a][tmp.b] = L[tmp.b][tmp.a] = min(L[tmp.a][tmp.b], tmp.len);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
}

int fd(int x){
    return p[x]==x ? x : p[x]=fd(p[x]);
}

void uni(int a, int b){
    if(r[a] > r[b])
        p[b] = a;
    else{
        p[a] = b;
        if(r[a] == r[b])
            r[b]++;
    }
}

bool Kruskal(){
    for(int i=0; i<v.size(); i++){
        int a = fd(v[i].a), b = fd(v[i].b);
        if(a != b){
            uni(a, b);
            MST += v[i].len;
            v1[v[i].a].push_back(v[i].b);

        }else{
            v2.push_back(v[i]);
            L[v[i].a][v[i].b] = L[v[i].b][v[i].a] = 0;
        }
    }
    return v1.size() == n-1;
}

int dfs(int a, int b){
    if(ok && a == b) return L[a][b];
    ok = true;
    int mx = 0;
    vis[a] = true;
    for(int i=0; i<v1[a].size(); i++){
        if(!vis[v1[a][i].b] && dfs(v1[a][i], b)){
            mx = v1
        }
    }
}
int secondMST(){
    delta = 1000000;
    //printf("%d===\n", v2.size());
    for(int i=0; i<v2.size(); i++){
        ok = false;
        memset(vis, false, sizeof(vis));
        vis[v2[i].b] = true;
        int t = v2[i].len-dfs(v2[i].a, v2[i].b);
        //printf("%d\n", t);
        delta = delta>t ? t : delta;
    }
    return delta != 1000000;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        printf("Case #%d : ", i);
        if(!Kruskal())
            puts("No way");
        else if(!secondMST())
            puts("Now second way");
        else
            printf("%d\n", delta);
    }
    return 0;
}

