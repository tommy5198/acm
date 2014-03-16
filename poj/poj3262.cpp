#include<cstdio>
#include<algorithm>
using namespace std;

struct Cow{
    double r;
    int t, d;
    bool operator<(const Cow &tmp)const{
        return r > tmp.r;
    }
}cow[100000];

int main(){
    int n;
    long long dpt = 0, flower = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        double a, b;
        scanf("%d%d", &cow[i].t, &cow[i].d);
        cow[i].r = (double)cow[i].t/cow[i].d;
    }
    sort(cow, cow+n);
    for(int i=0; i<n; i++){
        flower += dpt*2*cow[i].t;
        dpt += cow[i].d;
    }
    printf("%lld\n", flower);
    return 0;
}
