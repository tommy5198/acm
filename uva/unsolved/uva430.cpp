#include<cstdio>

bool init(){
    if(scanf("%d", &n) == EOF) return false;
    for(m=0; getchar() == ' '; m++)
        scanf("%d", v+m);
    dp[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=n; j>=v[i]; j--)
            if(dp[j-v[i]])
                dp[j] += dp[j-v[i]];
    for(int i=1; i<m; i++)
        sum[i] = sum[i-1] + dp[i];

}

void sol(){
    for(int i=0; i<m; i++){
        if(!i) printf(" ");
        if(!v[i]) printf("0");
        else printf("%d", sum[n - 1]);
    }
    puts("");
}

int main(){
    while(init())
        sol();
    return 0;
}
