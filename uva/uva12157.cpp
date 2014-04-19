#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        int n, j = 0, m = 0;
        int dur;
        scanf("%d", &n);
        while(n--){
            scanf("%d", &dur);
            m += dur/30 + 1;
            j += dur/60 + 1;
        }
        if(m*10 < j*15)
            printf("Case %d: Mile %d\n", i, m*10);
        else if(m*10 > j*15)
            printf("Case %d: Juice %d\n", i, j*15);
        else
            printf("Case %d: Mile Juice %d\n", i, m*10);
    }
    return 0;
}
