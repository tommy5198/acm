#include<cstdio>

int main(){
    int n[4];
    while(scanf("%d%d%d%d", n, n+1, n+2, n+3), n[0]||n[1]||n[2]||n[3])
        printf("%d\n", (120 + ((40+n[0]-n[1])%40) + ((40+n[2]-n[1])%40) + ((40+n[2]-n[3])%40) ) * 9);

    return 0;
}
