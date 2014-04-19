#include<cstdio>

int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        int price[257] = {0};
        unsigned char c;
        int k;
        int sum = 0;
        scanf("%d",&k);
        while(k--){
            getchar();
            c = getchar();
            scanf("%d", &price[c]);
        }
        scanf("%d",&k);
        getchar();
        while(k--){
            for(c = getchar(); c&&c!='\n'; c=getchar())
                sum += price[c];
            sum += price[c];
        }

        printf("%d.%02d$\n", sum/100, sum%100);
    }
    return 0;
}
