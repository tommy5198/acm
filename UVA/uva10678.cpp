#include<cstdio>
#include<cmath>

int main(){
    double pi = 2*acos(0);
    int n;
    double d, l, a, b;
    scanf("%d", &n);
    while(n--){
        scanf("%lf %lf", &d, &l);
        a = sqrt(l*l - d*d)/2;
        b = l/2;
        printf("%.3lf\n", pi*a*b);
    }
    return 0;
}
