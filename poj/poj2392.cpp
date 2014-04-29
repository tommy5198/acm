#include<cstdio>
#include<algorithm>
using namespace std;

struct block{
    int h, a, c;
    bool operator<(const block &t)const{
        return a<t.a;
    }
}b[500];

bool dp[40001];

int main(){
    int k, ans = 0;
    scanf("%d", &k);
    for(int i=0; i<k; i++)
        scanf("%d%d%d", &b[i].h, &b[i].a, &b[i].c);
    sort(b, b+k);
    dp[0] = true;
    for(int i=0; i<k; i++)
        for(int j=0; j<b[i].c; j++)
            for(int x=b[i].a; x>=b[i].h; x--){
                dp[x] = dp[x-b[i].h] ? true : dp[x];
                ans = dp[x]&&x>ans ? x : ans;
            }
    printf("%d\n", ans);
    
    return 0;
}
