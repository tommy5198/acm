// GCD
#include<cstdio>

int GCD(int a, int b)
{
    return b ? GCD(b, a%b) : a;
}

int main(){
    int n, G[501] = {0};
    for(int i=2; i<501; i++){
        G[i] += G[i-1];
        for(int j = 1; j<i; j++)
            G[i] += GCD(j, i);
    }
    while(scanf("%d", &n), n)
        printf("%d\n", G[n]);
    return 0;
}
