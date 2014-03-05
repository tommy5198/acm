#include<cstdio>
#define INF 10000000000
int main(){

    int j = 0;
    bool odd = true;
    long long tmp, a[10001] = {0};
    for(int i = 0; scanf("%lld", &tmp) != EOF; i++){

        for(j = i; j != 0; j--){
            if(a[j - 1] > tmp)
                a[j] = a[j - 1];
            else
                break;
        }
        a[j] = tmp;

        if(odd){
            printf("%lld\n", a[i/2]);
            odd = false;
        }else{
            printf("%lld\n", (a[i/2]+a[1 + i/2])/2);
            odd = true;
        }
    }
    return 0;
}
