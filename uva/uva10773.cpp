#include<cstdio>
#include<cmath>

int main(){
    int T;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        double d, v, u;
        scanf("%lf%lf%lf", &d, &v, &u);
        if(v >= u || !v)
            printf("Case %d: can't determine\n", ca);
        else    
            printf("Case %d: %.3lf\n", ca, d/sqrt(u*u-v*v)-d/u);
    }
    return 0;
}
