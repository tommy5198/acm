#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        unsigned int used[3125] = {0};
        int n, num, cnt = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &num);
            if( !(used[(num-1)/32] & (1<<((num-1)%32))) ){
                cnt++;
                used[(num-1)/32] |= (1<<((num-1)%32));
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
