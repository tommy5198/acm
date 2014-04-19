#include<cstdio>

char url[10][101];
int v[10];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int mx = 0;
        for(int j=0; j<10; j++){
            scanf("%s%d", url[j], v+j);
            mx = mx>v[j] ? mx : v[j];
        }
        printf("Case #%d:\n", i);
        for(int j=0; j<10; j++)
            if(mx == v[j])
                puts(url[j]);
    }
    return 0;
}
