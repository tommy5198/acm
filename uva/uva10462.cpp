//2nd MST for template(?
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Line{
    int a, b;
    int len;
    bool block;
    bool operator<(const Line &t)const{
        return len < t.len;
    }
} tmp;
int delta;
bool vis[101], ok, snd;
int n, m, MST;
int L[101][101];
int p[101], r[101];
vector<int> V;
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
    snd = false;
    V.clear();
    MST = 0;
    v.clear();
    while(m--){
        scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.len);
        tmp.block = false;
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
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].block) continue;
        int a = fd(v[i].a), b = fd(v[i].b);
        if(a != b){
            uni(a, b);
            MST += v[i].len;
            if(!snd) V.push_back(i);
            cnt++;
        }
    }

    return cnt == n-1;
}

bool secondMST(){
    int mst = MST, mi = 10000000;
    snd = true;
    for(int i=0; i<V.size(); i++){
        v[V[i]].block = true;
        MST = 0;
        for(int j=1; j<=n; j++){
            p[j] = j;
            r[j] = 0;
        }
        if(Kruskal())
            mi = min(mi, MST);
        v[V[i]].block = false;
    }
    delta = mi - mst;
    MST = mst;
    return mi != 10000000;
}
int main(){
    int T, mst;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        printf("Case #%d : ", i);
        if(!Kruskal())
            puts("No way");
        else if(!secondMST())
            puts("No second way");
        else
            printf("%d\n", MST+delta);
    }
    return 0;
}

