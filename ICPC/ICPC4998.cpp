#include<cstdio>
long long MOD = 1000000000000LL;
long long HMOD = 1000000LL;

long long ab[40];
long long a;

long long mul(long long a, long long b){
    long long x = a/HMOD, X = a%HMOD;
    long long y = b/HMOD, Y = b%HMOD;
    long long r = (x*Y + X*y)*HMOD + X*Y;
    return r%MOD;
}

long long poow( long long a,  long long b){
    long long ans = 1;
    for(int i=0; b; i++, b>>=1)
        if(b&1)
            ans = mul(ans, ab[i]);
        


    return ans;
}

void pre( long long a){
    for(int i=0; i<40; i++){
        ab[i] = i?mul(ab[i-1],ab[i-1]):a;
        ab[i] %= MOD;
    }

}

int main(){
    int ca = 1;
    while(scanf("%lld", &a), a){
        long long ans = 99;
        pre(a);
        while(ans){
            if(poow(a, ans)%100 == ans)
                break;
            ans--;
        }
        for(long long ten=100, i=3; i<=12; i++){
            for(long long k=1; k<10; k++){
                if(poow(a, ans+k*ten)%(ten*10) == ans+k*ten ){
                    ans = ans+k*ten;
                    break;
                }
            }
            ten *= 10;
        }
        printf("Case %d: Public Key = %lld Private Key = %lld\n", ca++, a, ans);
    }
    return 0;
}
