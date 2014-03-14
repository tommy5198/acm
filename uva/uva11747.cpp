//MST by Kruskal
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

int n, m;
int p[1001], r[1001];
vector<Line> v;
vector<int> ans;

bool init(){
    if(scanf("%d%d", &n, &m), !n&&!m)
        return false;
    for(int i=0; i<n; i++){
        p[i] = i;
        r[i] = 0;
    }
    v.clear();
    ans.clear();
    while(m--){
        scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.len);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
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

void sol(){
    for(int i=0; i<v.size(); i++){
        int a = fd(v[i].a), b = fd(v[i].b);
        if(a != b)
            uni(a, b);
        else
            ans.push_back(v[i].len);
    }
}

int main(){
    while(init()){
        sol();
        if(ans.size() == 0){
            puts("forest");
            continue;
        }
        bool sp = false;
        for(int i=0; i<ans.size(); i++){
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
