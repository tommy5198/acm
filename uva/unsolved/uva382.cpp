#include<cstdio>

int ans[60001];
int prime[50000];
int k;
bool nop[60001];

void init(){
    prime[0] = 2;
    k = 1;
    for(int i=3; i<=60000; i++){
        for(int j=0; j<k && prime[j]<=i/2; j++){
            if(i%prime[j] == 0){
                nop[i] = true;
                break;
            }
        }
        if(!nop[i]){
            prime[k++] = i;
            ans[i] = -1;
            continue;
        }
        int pre = 0, cnt = 2;
        for(int j=0; j<k && prime[j]<=i/2; j++){
            if(i%prime[j] == 0){
                if(pre == prime[j]){
                    ans 
                }
            }
        }
    }


}

int main(){
    int n;
    init();
    return 0;
    puts("PERFECTION OUTPUT");
    while(scanf("%d", &n), n){
        if(ans[n] > 0)
            printf("%5d  ABUNDANT\n", n);
        else if(ans[n] < 0)
            printf("%5d  DEFICIENT\n", n);
        else
            printf("%5d  PERFECT\n", n);
    }
    puts("END OF OUTPUT");
    return 0;
}
