#include<cstdio>

int n;
int a[100], p[100];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d", a+i, p+i);
}

void sol(){
    int ans = 0;
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(a[j] && (a[j]+10)*p[j] > a[j]*p[i] ){
                a[i] += a[j];
                a[j] = 0;
            }

    for(int i=0; i<n; i++)
        if(a[i]) ans += (a[i] + 10) * p[i];
    printf("%d\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        sol();
    }
    return 0;
}
