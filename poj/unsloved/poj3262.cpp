#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

long long sum, ans;
bool mode;
struct Cow{
    int t, d;
    long long flower()const{
        return (sum-d)*t*2;
    }
    bool operator<(const Cow &t)const{
        if(mode)
            return this->t < t.t;
        return this->t > t.t;
        //return this->flower()<t.flower();
    }
}cow[100000];

int main(){
    int n;
    sum = ans = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &cow[i].t, &cow[i].d);
        sum+=cow[i].d;
    }
    sort(cow, cow+n);
    for(int i = 0; i<n; i++){
        ans += cow[i].flower();
        sum -= cow[i].d;
    }
    printf("%lld\n", ans);
    return 0;
}
