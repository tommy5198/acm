#include<cstdio>

int main(){
    int T, a, b, c;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        scanf("%d%d%d", &a, &b, &c);
        printf("Case %d: %d\n", i, (a>b)?((a>c)?((b>c)?b:c):a):((b>c)?((a>c)?a:c):b));
    }
    return 0;
}
