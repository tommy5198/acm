#include<cstdio>
#include<algorithm>
using namespace std;

double a[1000];
double b[1001];
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        int n, x = 0, y = 0;
        int cnt[1001] = {0};
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%lf", a+i);
        for(int i=0; i<n; i++)
            scanf("%lf", b+i);
        sort(a, a+n);
        sort(b, b+n);
        b[n] = 2.0;
        for(int i=0, j=0; i<=n && j<n;)
            if(a[j] < b[i]){
                cnt[i]++;
                j++;
            }else
                i++;    
        for(int i=0, r=n-1; i<=n; i++)
            if(i >= y+cnt[i])
                y += cnt[i];
            else{
                r -= y+cnt[i]-i;
                y = i;
            }
        for(int i=n, r=n-1; i>=x; i--)
            if(i > r)
                x += cnt[i];
            else if(r-cnt[i] >= i-1)
                r -= cnt[i];
            else{
                x += i - 1 - r + cnt[i];
                r = i-1;                
            }
        printf("Case #%d: %d %d\n", t, y, x);
    }
    return 0;
}
