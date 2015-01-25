#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, d;
        scanf("%d%d", &n, &d);
        long long int dim[10] = {0};
        long long int sum = 0;
        long long int meet = 0;
        while(sum != n*(d-1)) {
            for(int i=0; i<n; i++) {
                dim[i]++;
                sum++;
                long long int xo = 0;
                for(int j=0; j<n; j++)
                    xo ^= dim[j];
                meet += xo * sum;
            }
        }
        printf("%lld\n", meet);
    }
    return 0;
}
