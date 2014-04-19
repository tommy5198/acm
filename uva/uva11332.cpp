#include<cstdio>

int main(){
    int n;
    while(scanf("%d", &n), n){
        int tmp;
        while(n > 9){
            tmp = 0;
            while(n){
                tmp += n%10;
                n/=10;
            }
            n = tmp;
        }
        printf("%d\n", n);
    }
    return 0;
}
