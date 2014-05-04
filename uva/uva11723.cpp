#include<cstdio>

int main(){
    int a, b, T = 1;
    while(scanf("%d%d", &a, &b), a){
        if((a-1)/b > 26)
            printf("Case %d: impossible\n", T++);
        else
            printf("Case %d: %d\n", T++, (a-1)/b);
    }
    return 0;
}
