#include<cstdio>

int main(){
    int n, T = 1;
    while(scanf("%d", &n), n){
        int tmp, ans = 0;
        while(n--){
            scanf("%d", &tmp);
            ans = tmp ? ans+1 : ans-1;
        }
        printf("Case %d: %d\n", T++, ans);
    }
    return 0;
}
