#include<cstdio>

int main(){
    int n;
    while(scanf("%d", &n), n){
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        while(n--){
            scanf("%d%d", &x, &y);
            if(a>x && b>y)
                puts("SO");
            else if(a>x && b<y)
                puts("NO");
            else if(a<x && b>y)
                puts("SE");
            else if(a<x && b<y)
                puts("NE");
            else
                puts("divisa");
        }
    }
    return 0;
}
