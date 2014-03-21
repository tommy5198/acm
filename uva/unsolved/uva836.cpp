#include<cstdio>

void init(){
    char c;
    getchar();
    while(getchar()){
        c = getchar();
        if(c == '\n') break;
        sum[n][0] = mat[n][0] = c-'0';
        m = 1;
        while((c = getchar()) != '\n'){
            mat[n][m] = c-'0';
            sum[n][m] = sum[n][m-1] + mat[n][m];
            m++;
        }
        n++;
    }
}

void sol(){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=0; k<m; k++){
                dp[k] += mat[j][k];
                if(tmp >= 0) tmp +=dp[k];
                else tmp
            }
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
    }
    return 0;
}
