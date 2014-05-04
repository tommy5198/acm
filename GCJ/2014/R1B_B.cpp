#include<cstdio>

int main(){
    int T, a, b, k, ans;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        ans = 0;
        scanf("%d%d%d", &a, &b, &k);
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                if((i&j) < k) ans++;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
