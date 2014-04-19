#include<cstdio>

int main(){
    int n, b, h, w;
    while(scanf("%d%d%d%d", &n, &b, &h, &w) != EOF){
        int mi = b+1;
        while(h--){
            int p, a;
            scanf("%d", &p);
            for(int i=0; i<w; i++){
                scanf("%d", &a);
                if(a >= n) mi = mi<p*n ? mi : p*n;
            }
        }
        if(mi == b+1)
            puts("stay home");
        else
            printf("%d\n", mi);
    }
    return 0;
}
