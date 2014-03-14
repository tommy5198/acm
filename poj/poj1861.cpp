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
vector<Line> v, ans;

void init(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        p[i] = i;
        r[i] = 0;
    }
    while(m--){
        scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.len);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
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

int sol(){
    int mx = 0;
    for(int i=0; i<v.size(); i++){
        int a = fd(v[i].a), b = fd(v[i].b);
        if(a != b){
            ans.push_back(v[i]);
            mx = mx<v[i].len ? v[i].len : mx;
            uni(a, b);
        }
    }
    return mx;
}

int main(){
    init();
    printf("%d\n", sol());
    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d %d\n", ans[i].a, ans[i].b);
    return 0;
}
