#include<cstdio>

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j) printf(" ");
            if(i == j) printf("%d", k);
            else printf("0");
        }
        puts("");
    }
    return 0;
}
