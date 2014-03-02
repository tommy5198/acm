//brute force 0ms
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n;
    long long cow[10000], sum = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%lld", &cow[i]);
    sort(cow, cow+n);
    for(int i=1; i<n; i++)
        sum += (cow[i] - cow[i-1]) * (n - i) * i;
    printf("%lld\n", 2*sum);
    return 0;
}
