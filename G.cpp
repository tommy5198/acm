#include<cstdio>
#define mod 1000000007
long long two[31], value[31];

void init(){
    two[0] = 1;
    for(int i=1; i<31; i++){
        two[i] = two[i-1]*2;
    }
}

void build(long long x){
    value[0] = x%mod;
    for(int i=1; i<31; i++)
        value[i] = (value[i-1]*value[i-1])%mod;

}

long long sol(long long v, long long d){
    for(int i=30; i>=0; i--){
        if(d == two[i])
            return value[i];
        else if(d > two[i])
            return (sol(v, two[i])*sol(v, d-two[i]))%mod;
    }
}
int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        long long d, v;
        scanf("%lld%lld", &d, &v);
        if(d == 0)
            printf("Case %d: 1\n", i);
        else{
            build(v-1);
            printf("Case %d: %lld\n", i, sol(v-1, d)+sol(v-1, d-1)+2);
        }
    }
    return 0;
}
