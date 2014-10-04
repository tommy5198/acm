#include<cstdio>

int a[1001];

int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        int n, sum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", a+i);
            for(int j=0; j<i; j++)
                sum += a[i] >= a[j];
        }
        printf("%d\n", sum);
    }
    return 0;
}
