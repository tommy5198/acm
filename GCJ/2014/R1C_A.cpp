#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        long long k;
        for(int i=1; i<=40; i++){
            k = 1<<i;
            if(k>b || b%k){
                k = k>>1;
                break;
            }
        }
        if(b != k)
    }
}
