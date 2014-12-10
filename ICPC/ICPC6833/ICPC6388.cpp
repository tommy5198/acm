#include<cstdio>

int main(){
    long long a, b, A, k;
    char c;

    while(scanf("%lld", &a) != EOF) {
        k = a;
        A = 0;
        while( (c=getchar()) != '\n'){
            scanf("%lld", &b);
            if(c == '+'){
                A += k;
                k = b;
                a += b;
            }else{
                k *= b;
                a *= b;
            }
        }
        A += k;
        scanf("%lld", &b);
        if(a == b && A == b)
            puts("U");
        else if(a == b)
            puts("L");
        else if(A == b)
            puts("M");
        else
            puts("I");


    }
    return 0;
}
