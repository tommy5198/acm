#include<cstdio>
#include<algorithm>
using namespace std;

 long long num[2000005], ans;
int main(){

    int n;

    int d[12], j = 0;
    d[0] = 1;
    for(int i=1; i<12; i++)
        d[i] = d[i-1]*4;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%I64d", &num[i]);
        if(i == d[j])
            j++;
    }
    j--;
    sort(num+1, num+n+1);
    for(int i = 1, x = j-1; i<=n; i++){

        ans += num[i]*(j-x);
        if(i == n - d[x])
            x--;
    }
    printf("%I64d", ans);
    return 0;
}
