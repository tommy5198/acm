#include<cstdio>

int ca;
long long dp[101][34][34][100];

void init(){
    for(int i=1; i<=100; i++){
        dp[i][0][1][1%i] = 1;
        for(int x=0; x<=32; x++)
            for(int y=0; y<=32; y++)
                for(int j=0; j<i; j++){
                    dp[i][x+1][y][(j<<1)%i] += dp[i][x][y][j];
                    dp[i][x][y+1][((j<<1)+1)%i] += dp[i][x][y][j];
                }     
    }
}

void sol(){
    int n, k;
    scanf("%d%d", &n, &k);
    if(n&1|!k)
        printf("Case %d: 0\n", ca++);
    else
        printf("Case %d: %lld\n", ca++, dp[k][n>>1][n>>1][0]);
}

int main(){
    int T;
    scanf("%d", &T);
    ca = 1;
    init();
    while(T--)
        sol();
    
    return 0;
}
