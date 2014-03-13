//MST by kruskal
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
}tmp;
int n, m;
int p[101];
vector<Line> v;

int fd(int x){
    return p[x]==x ? x : p[x] = fd(p[x]);
}

void uni(int a, int b){
    if(a != b)
        p[a] = b;
}

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        p[i+1] = i+1;
        for(int j=0; j<n; j++){
            scanf("%d", &tmp.len);
            tmp.a = i+1;
            tmp.b = j+1;
            if(i < j)
                v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end());
    scanf("%d", &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        uni(fd(a), fd(b));
    }
}

int sol(){
    int ans = 0;
     for(int i=0; i<v.size(); i++){
        int a = fd(v[i].a), b = fd(v[i].b);
        if(a != b){
            ans += v[i].len;
            uni(a, b);
        }
    }
    return ans;
}

int main(){
    init();
    printf("%d\n", sol());
    return 0;
}
