#include<cstdio>

int main(){
    int i, x, y, n, step[50000] = {0};
    scanf("%d", &n);
    for(int i = 1; i<50000; i++){
        step[i] += step[i-1] + (i+1)/2;
    }
    while(n--){
        scanf("%d%d", &x, &y);
        for(i=0; i<50000 && step[i] < y-x; i++) ;
        printf("%d\n", i);
    }
    return 0;
}
