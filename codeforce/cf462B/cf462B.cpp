#include<cstdio>
#include<algorithm>
using namespace std;


int main(){
    long long n, m;
    char str[100001];
    long long used[26] = {0};
    long long ans = 0;
    scanf("%lld%lld%s", &n, &m, str);
    for(int i=0; i<n; i++)
        used[str[i]-'A']++;
    sort(used, used+26);
    for(int i=26-1; m; i--){
        if(~i == 0) puts("asd");
        if(used[i] <= m) {
            ans += used[i]*used[i];
            m -= used[i];
        }else {
            ans += m*m;
            m = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

