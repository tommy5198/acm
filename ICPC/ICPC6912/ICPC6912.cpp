// brute backtracking
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int p[200];
int light[1001];
int n, m, st, Max;

void rec(int used, int cnt){
    if(cnt == st){
        int ans = 0;
        for(int i=1; i<=n; i++)
            ans += light[i];
        for(int i=st; i<m; i++){
            int ad = 0;
            for(int j=1; j*p[i]<=n; j++)
                ad = light[j*p[i]] ? ad-1 : ad+1;
            if(ad > 0)
                ans += ad;
        }
        Max = ans<Max ? Max : ans;
        return ;
    }
    rec(used, cnt+1);
    for(int i=1; i*p[cnt] <= n; i++)
        light[i*p[cnt]] ^= 1;
    rec(used|(1<<cnt), cnt+1);
    for(int i=1; i*p[cnt] <= n; i++)
        light[i*p[cnt]] ^= 1;
}

int main(){
    int T, ca = 1;
    scanf("%d", &T);
    while(T--){
        int low;
        scanf("%d%d", &n, &m);
        low = sqrt(n);
        st = m;
        for(int i=0; i<m; i++)
            scanf("%d", p+i);
        sort(p, p+m);
        for(int i=0; i<m; i++){
            if(st == m && p[i] > low)
                st = i;
        }
        Max = -1;
        rec(0, 0);
        printf("Case #%d: %d\n", ca++, Max);
    }
    return 0;
}
