//MST bt Kruskal
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Line{
    int a, b, len;
    bool operator<(const Line &t)const{
        return len < t.len;
    }
}tmp;
int n, m;
vector<Line> v;
int p[2001], r[2001];

void init(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        p[i] = i;
        r[i] = 0;
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.len);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
}

int findset(int x){
    return p[x]==x ? x : p[x] = findset(p[x]);
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

int sol(){
    int mx = -1;
    for(int i=0; i<v.size(); i++){
        int a = findset(v[i].a), b= findset(v[i].b);
        if(a != b){
            uni(a, b);
            mx = mx>v[i].len ? mx : v[i].len;
        }
    }
    return mx;
}

int main(){

    init();
    printf("%d\n", sol());
    return 0;
}
