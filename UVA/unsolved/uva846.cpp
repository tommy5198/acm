#include<cstdio>

int main(){
    long long a, b, n;
    long long mx = 65537;
    long long ans[65537];
    for(long long i=0; i<mx; i++){
        ans[i] = i*(i+1)/2;
    }
    scanf("%lld", &n);
    while(n--){
        scanf("%lld%lld", &a, &b);
        int i;
        for(i=0; i<mx; i++)
            if(b - a <= ans[i])
                break;
        printf("%d\n", i);
    }
    return 0;
}
