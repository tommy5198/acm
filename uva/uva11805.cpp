#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca<=T; ca++){
        int n, k, p;
        scanf("%d%d%d", &n, &k, &p);
        k = k==n ? 0 : k;
        printf("Case %d: %d\n", ca, (p+k)%n == 0 ? n : (p+k)%n);
    }
    return 0;
}
