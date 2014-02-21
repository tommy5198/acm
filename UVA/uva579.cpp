#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    float h,m;
    while(scanf("%f:%f", &h, &m)!=EOF){
        if(!h && !m)
            break;
        float ans = 0.0;
        h = (h==12.)?0.:h;
        h = h*5 + m/12;
        h = (h>=60)?h-60:h;
        ans = abs(h - m);
        ans = (ans > 30)?60-ans:ans;
        printf("%.3f\n", ans*6);
    }
    return 0;
}
