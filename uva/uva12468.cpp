#include<cstdio>

int main(){
    int a, b, t;
    while(scanf("%d%d", &a, &b), a!=-1){
        if(a > b){
            t = a; a = b; b = t;
        }
        printf("%d\n", (b-a < 100+a-b) ? b-a : 100+a-b);
    }
    
    return 0;
}
