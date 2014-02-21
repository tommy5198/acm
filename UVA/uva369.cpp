#include<cstdio>

int main(){
    double n, m;
    while(scanf("%lf%lf", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        double ans = 1;
        int N = n, M = m;
        while(m > 0){
            ans *= n/m;
            n--;
            m--;
        }
        printf("%d things taken %d at a time is %.0lf exactly.\n", N, M, ans);

    }
    return 0;
}
