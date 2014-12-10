#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    if(n&1)
        puts("black");
    else
        puts("white\n1 2");
    return 0;
}

