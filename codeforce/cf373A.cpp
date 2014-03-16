#include<cstdio>

int main(){
    int k;
    bool fail = false;
    int sum[10] = {0};
    k = getchar() - '0';
    getchar();
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int a = getchar();
            if(a != '.'){
                sum[a-'0']++;
                if(sum[a-'0'] > 2*k)
                    fail = true;
            }
        }
        getchar();
    }
    if(fail)
        puts("NO");
    else
        puts("YES");
    return 0;
}
