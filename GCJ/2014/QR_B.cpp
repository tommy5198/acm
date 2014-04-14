#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        double c, f, x, pre = 2;
        double ans = 0;
        scanf("%lf%lf%lf", &c, &f, &x);
        while((x-c)/pre > x/(pre+f)){
            ans += c/pre;
            pre += f;
        }
        ans += x/pre;
        printf("Case #%d: %.7lf\n", t, ans);
    }
    return 0;
}
