#include<cstdio>

int main(){
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    if(a > b){
        printf("%I64d\n",a*a - b*b);
        for(int i=0; i<b; i++)
            printf("x");
        for(int i=0; i<a; i++)
            printf("o");
    }else if(a == b){

        printf("%I64d\n", a*a - (b/2)*(b/2) - ((b+1)/2)*((b+1)/2));
        for(int i=0; i<b/2; i++)
            printf("x");
        for(int i=0; i<a; i++)
            printf("o");
        for(int i=0; i<(b+1)/2; i++)
            printf("x");
    }else{
        printf("%I64d\n", a - (b/(a+1))*(b/(a+1))*((a+1)-(b%(a+1))) - (b%(a+1))*(b/(a+1)+1)*(b/(a+1)+1));
        for(int i=0; i<=a; i++){
            for(int j=0; j<b/(a+1); j++)
                printf("x");
            if(i < b%(a+1))
                printf("x");
            if(i != a)
                printf("o");
        }
    }
    return 0;
}
