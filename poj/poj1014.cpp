// DP knap
#include<cstdio>

int sum, n[7];

bool init(){
    sum = 0;
    for(int i=1; i<=6; i++){
        scanf("%d", n+i);    
        n[i] = n[i]>6 ? 6 - (n[i]%2) : n[i]; // amazing
        sum += n[i]*i;
    }
    if(!sum) return false;
    else return true;
}

bool sol(){
    bool dp[128] = {false};
    if(sum % 2) return false;
    else sum /= 2;
    dp[0] = true;
    for(int i=1; i<=6; i++)
        for(int j=0; j<n[i]; j++)
            for(int k=sum; k>=i; k--)
                dp[k] = dp[k-i] ? true : dp[k];
    return dp[sum];
}

int main(){
    int T = 1;
    while(init()){
        printf("Collection #%d:\n", T++);
        if(sol())
            puts("Can be divided.\n");
        else
            puts("Can't be divided.\n");
    }
    return 0;
}
