#include<cstdio>
#include<algorithm>

int mode;
struct Cow{
    int f, s, o;
    bool operator<(const Cow &t)const{
        if(mode == 0)
            return f < t.f;
        else
            return s < t.s;
    }
}cow[50001];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &cow[i].f, &cow[i].s);
        cow[i].o = i;
    }
    std::sort(cow, cow+n);
    mode = 1;
    std::sort(cow+n-k, cow+n);
    printf("%d\n", cow[n-1].o + 1);
    return 0;
}
