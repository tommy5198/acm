//MST
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Line{
    int a, b;
    int len;
    bool operator<(const Line &t)const{
        return len < t.len;
    }
} tmp;

int n, m, ans;
int p[11], r[11];
vector<Line> v[2];

bool init(){
    if(scanf("%d", &n), !n)
        return false;
    scanf("%d", &m);
    for(int i=1; i<=n; i++){
        p[i] = i;
        r[i] = 0;
    }
    ans = 0;
    v[0].clear();
    v[1].clear();
    while(m--){
        scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.len);
        v[0].push_back(tmp);
    }
    sort(v[0].begin(), v[0].end());
    return true;
}

int fd(int x){
    return p[x]==x ? x : p[x] = fd(p[x]);
}

void uni(int a, int b){
    if(a == b) return ;
    if(r[a] > r[b])
        p[b] = a;
    else{
        p[a] = b;
        if(r[a] == r[b])
            r[b]++;
    }
}

bool sol(int T){
    int cnt = 0;
    for(int i=0; i<v[T].size(); i++){
        int a = fd(v[T][i].a), b = fd(v[T][i].b);
        if(a != b){
            uni(a, b);
            ans += v[T][i].len;
            cnt++;
        }else if(!T)
            v[1].push_back(v[0][i]);
    }
    if(cnt != n-1)
        return false;
    if(!T){
        sort(v[1].begin(), v[1].end());
        for(int i=1; i<=n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }
    return true;
}

int main(){
    while(init()){
        if(sol(0) && sol(1))
            printf("%d\n", ans);
        else
            puts("No way!");
    }
    return 0;
}


