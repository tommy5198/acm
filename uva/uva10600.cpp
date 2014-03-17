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

bool vis[101], ok;
int n, m, MST;
int L[101][101];
int p[101], r[101];
vector<Line> v, v2;
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

int Kruskal(){
    for(int i=0; i<v.size(); i++){
        int a = fd(v[i].a), b = fd(v[i].b);
        if(a != b){
            uni(a, b);
            MST += v[i].len;
            L[v[i].a][v[i].b] = L[v[i].b][v[i].a] = v[i].len;
        }else{
            v2.push_back(v[i]);
            //L[v[i].a][v[i].b] = L[v[i].b][v[i].a] = 0;
        }
    }
    return MST;
}

int dfs(int a, int b){
    if(ok && L[a][b]) return L[a][b];
    ok = true;
    int mx = 0;
    vis[a] = true;
    for(int i=1; i<=n; i++)
        if(!vis[i] && L[a][i]){
            int nt = dfs(i, b);
            if(nt){
                mx = L[a][i]>nt ? L[a][i] : nt;
                break;
            }
        }
    return mx;
}
int secondMST(){
    int delta = 1000000;
    //printf("%d===\n", v2.size());
    for(int i=0; i<v2.size(); i++){
        ok = false;
        memset(vis, false, sizeof(vis));
        vis[v2[i].b] = true;
        int t = v2[i].len-dfs(v2[i].a, v2[i].b);
        //printf("%d\n", t);
        delta = delta>t ? t : delta;
    }
    return MST+delta;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b;
        init();
        a = Kruskal();
        b = secondMST();
        printf("%d %d\n", a, b);
    }
    return 0;
}

