//sort
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct job{
    int j, b;
    bool operator<(const job &t)const{
        return j > t.j;
    }
}tmp;
int main(){
    int n, T = 1;
    while(scanf("%d", &n), n){
        int b, j, finish = 0, brief = 0;
        vector<job> v;
        while(n--){
            scanf("%d%d", &tmp.b, &tmp.j);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            brief += v[i].b;
            finish = finish>brief+v[i].j ? finish : brief+v[i].j;

        }
        printf("Case %d: %d\n", T++, finish);
    }
    return 0;
}
