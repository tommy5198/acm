// 0 ~ 2147483647 => 92681 => up bound
// count how long in each stepnum
// stepnum  0  1  2  3  4  5  6  7...
// dis_add   0  1  1  2  2  3  3  4...
// and we get the pattern !
#include<cstdio>
long long step[2000000];

int main(){
    int i, x = 1, y, n;
    scanf("%d", &n);
    for(int i = 1; i<2000000; i++){
        step[i] += step[i-1] + (i+1)/2;
    }
    //printf("%lld\n", step[1999999]);
    while(n--){
            for(int i = 1; i<2200000; i++){
        x *= i;
    }
        scanf("%d%d", &x, &y);
        for(i=0; i<92681 && step[i] < y-x; i++) ;
        printf("%d\n", i);
    }
    return 0;
}
