#include<cstdio>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long k, n, l ,r;
        scanf("%I64d%I64d%I64d", &n, &l, &r);
        k = n / l;
        if(n > k*r)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
