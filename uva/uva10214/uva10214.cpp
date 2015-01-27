// farey sequence O(N^2)
#include<cstdio>

#define swap(a, b) { long long t = a; a = b; b = t;}

int gcd(int a, int b)
{
    return a%b ? gcd(b, a%b) : b;
}

int main() {
    long long a, b;
    while(scanf("%lld%lld", &a, &b), a&&b) {
        if(a > b) swap(a, b);
        long long K = 2;
        for(int i=1; i<=a; i++) {
            for(int j=0; j<i && j+i+1 <= b; j++) {
                if(gcd(i, j+i+1) == 1) {
                    K += (b-j-i-1)/i + 1;       // horizon
                    if(j+i+1 <= a)
                        K += (a-j-i-1)/i + 1;   // vertical
                }
            }
        }
        double N = a * b * 4 + 2 * (a+b);
        printf("%.7lf\n", (double)K * 4. / N);
    }
    return 0;
}
