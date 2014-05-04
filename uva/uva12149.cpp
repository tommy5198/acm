#include<cstdio>

int main(){
    int n, ans[101] = {0};
    for(n=1; n<=100; n++)
        for(int i=1; i<=n; i++)
            ans[n] += (n-i+1)*(n-i+1);
    while(scanf("%d", &n), n)
        printf("%d\n", ans[n]);
    
    return 0;
}
