#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        double a, b, z;
        scanf("%lf%lf%lf", &a, &b, &z);
        printf("%.0lf\n", (a - (a+b)/3) / ((a+b)/3) * z);
    }
    return 0;
}
