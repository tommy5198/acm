#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        int n, a[10];
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", a+i);
        sort(a, a+n);
        printf("Case %d: %d\n", ca, a[n/2]);
    }
    return 0;
}
