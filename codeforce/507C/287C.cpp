#include<cstdio>

int main(){
    int h;
    long long n;
    scanf("%d%I64d", &h, &n);
    long long mx = ((long long)1) << h;
    long long mi = 1;
    long long ans = h;
    for(int i=h, j = 0; i; i--) {
        long long mid = (mx + mi) / 2;
        if(n > mid && !j || n <= mid && j)
            ans += (((long long)1) << i) - 1;
        else
            j ^= 1;
        if(n > mid)
            mi = mid + 1;
        else
            mx = mid;
    }
    printf("%I64d\n", ans);
    return 0;
}
