#include<cstdio>

int main(){
    int T, sum = 0;
    scanf("%d", &T);
    while(T--){
        char str[7];
        int a;
        scanf("%s", str);
        if(str[0] == 'd'){
            scanf("%d", &a);
            sum += a;
        }else
            printf("%d\n", sum);
    }
    return 0;
}
