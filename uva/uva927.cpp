#include<cstdio>
#include<cmath>

long long int cof[21];
int main(){
    int C;
    scanf("%d", &C);
    while(C--){
        int n;
        long long int d, k, tmp;
        scanf("%d", &n);
        for(int i=0; i<=n; i++)
            scanf("%lld", cof+i);
        scanf("%lld%lld", &d, &k);
        tmp = d;
        d = sqrt(2.0*k/d);
        d += (2*k) > (d*d+d)*tmp;
        tmp = d;
        for(int i=1; i<=n; i++, d*=tmp)
            cof[0] += cof[i] * d;
        printf("%lld\n", cof[0]);
    }
    return 0;
}
