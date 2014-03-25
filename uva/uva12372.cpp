#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        int n;
        bool ans = true;
        for(int i=0; i<3; i++){
            scanf("%d", &n);
            if(n > 20) ans = false;
        }
        if(ans)
            printf("Case %d: good\n", i);
        else
            printf("Case %d: bad\n", i);
    }
    return 0;
}
