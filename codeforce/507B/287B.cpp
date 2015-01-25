#include<cstdio>
#include<cmath>
int main(){
    double r, x1, x2, y1, y2;
    scanf("%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2);
    double dis = sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)  );
    long long div = dis/(2.0*r);
    if(div*2*r != dis) div++;
    printf("%I64d\n", div);
    return 0;
}
