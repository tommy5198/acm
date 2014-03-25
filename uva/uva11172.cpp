#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        if(n == m)
            puts("=");
        else if(n > m)
            puts(">");
        else
            puts("<");
    }
    return 0;
}
