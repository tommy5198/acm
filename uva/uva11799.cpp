#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    for(int t=1; t<=n ;t++){
        int k, mx = 0, num;
        scanf("%d", &k);
        while(k--){
            scanf("%d", &num);
            mx = mx>num ? mx : num;
        }
        printf("Case %d: %d\n", t, mx);
    }
    return 0;
}
