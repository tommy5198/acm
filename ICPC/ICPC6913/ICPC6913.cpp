#include<cstdio>

char AB[2] = {'B', 'A'};
char p[2001];
int idx[2], cnt[2], mul[2];

int main(){
    int T, ca = 1;
    scanf("%d", &T);
    while(T--){
        int n, m, k;
        scanf("%d%d%d%s", &n, &m, &k, p);
        int win = 'B' - p[m-1], lidx;
        cnt[win] = cnt[win^1] = mul[win] = mul[win^1] = 1;
        idx[win] = idx[win^1] = m-1;
        while(--idx[win^1] >= 0 && p[idx[win^1]] != AB[win^1]);
        while(~idx[win^1]){
            while(cnt[win] && cnt[win^1] < k*mul[win^1])
                cnt[win]--, cnt[win^1]++;
            if(!cnt[win]){
                cnt[win] = 1;
                if(p[--idx[win]] != AB[win]){
                    win ^= 1;
                    while(--idx[win^1] >= 0 && p[idx[win^1]] != AB[win^1]);
                    mul[win^1] = 1;
                }
            
            }
            if(cnt[win^1] == k*mul[win^1]){
                while(--idx[win^1] >= 0 && p[idx[win^1]] != AB[win^1]);
                cnt[win^1]++;
                mul[win^1]++;
            }
        }
        printf("Case #%d: %c\n", ca++, AB[win]);
    }
    return 0;
}
