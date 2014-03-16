#include<cstdio>

int main(){
    int n, k, N;
    int cnt = 0;
    scanf("%d%d", &n, &k);
    while(n--){
        bool fail = false;
        bool exist[10] = {false};
        scanf("%d", &N);
        while(N){
            exist[N%10] = true;
            N/=10;
        }
        for(int i=0; i<=k; i++){
            if(!exist[i])
                fail = true;
        }
        if(!fail) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
