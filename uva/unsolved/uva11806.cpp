#include<cstdio>
#define MOD 1000007
int dp[501][21][21];
int C[501][401];
int TMP[501];

void init(){
    TMP[0] = 1;
    for(int i=1; i<501; i++){
        TMP[i] = i * TMP[i-1];
        TMP[i] %= MOD;
    }
    for(int i=)

}
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        printf("Case %d: ", i);
        int m, n, k;
        scanf("%d%d%d", &m, &n, &k);
        printf("%d\n", dp[k][m][n]);
    }
    return 0;
}
