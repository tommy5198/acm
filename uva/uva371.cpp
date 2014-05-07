#include<cstdio>

int ans[1000000];


int main(){
    int a, b;
    while(scanf("%d%d", &a, &b), a||b){
        if(a>b){
            int t=a;
            a=b;
            b=t;
        }
        long long mx = 0, mxi = 1e14;
        for(int i=a; i<=b; i++){
            long long tmx = 1, tmp = i;
            while(1){
                if(tmp%2)
                    tmp = tmp*3 + 1;
                else if(tmp != 2)
                    tmp /= 2;
                else
                    break;
                tmx++;
            }
            if(tmx > mx){
                mx = tmx;
                mxi = i;
            }
        }
        printf("Between %d and %d, %lld generates the longest sequence of %lld values.\n", a, b, mxi, mx);
    }
    return 0;
}
