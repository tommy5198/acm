#include<cstdio>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, mx = 0, mi = 100;
        scanf("%d", &n);
        while(n--){
            int tmp;
            scanf("%d", &tmp);
            mx = mx>tmp ? mx : tmp;
            mi = mi<tmp ? mi : tmp;
        }
        printf("%d\n", (mx-mi)*2);
    }
    return 0;
}
