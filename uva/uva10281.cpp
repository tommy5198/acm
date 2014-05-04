#include<cstdio>

int main(){
    int hr, m, s, tm, pretm = 0;
    double km = 0, v = 0;
    while(scanf("%d:%d:%d", &hr, &m, &s) != EOF){
        tm = hr*3600+m*60+s;
        km += v*(tm-pretm)/3600.0;
        pretm = tm;
        if(getchar() == ' ')
            scanf("%lf", &v);
        else
            printf("%02d:%02d:%02d %.2lf km\n", hr, m, s, km);
    }
    return 0;
}
