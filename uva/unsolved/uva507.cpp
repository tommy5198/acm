#include<cstdio>

int n;
int num[20000], dp[20000];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n-1; i++)
        scanf("%d", num+i);
}

void sol(int T){
    int len = 0, mx = -1, ml = 0;
    int tmp, a, b;
    dp[0] = num[0];
    for(int i=1; i<n-1; i++){
        dp[i] = dp[i-1]>=0 ? dp[i-1]+num[i] : num[i];
        mx = mx>dp[i] ? mx : dp[i];
    }
    if(mx < 0){
        printf("Route %d has no nice parts", T);
        return ;
    }
    for(int i=n-2; i>=0; i--){
        if(!len && dp[i] == mx){
                len = 1;
                tmp = i+1;
        }else if(len && dp[i]>=0){
            len++;
            if(i == 0 && ml <= len){
                a = 0;
                b = tmp;
            }
        }
        else if(len && dp[i]<0){
            if(ml <= len){
                a = i+1;
                b = tmp;
                ml = len;
            }
            len = 0;
        }
    }
    printf("The nicest part of route %d is between stops %d and %d\n", T, a+1, b+1);
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        sol(i);
    }
    return 0;
}
