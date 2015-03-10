#include<cstdio>

int main() {
    int T, n, m;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i< 1<<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++)
                if(i & (1<<j))
                    cnt++;
            if(cnt == m) {
                for(int j=n-1; ~j; j--)
                    printf(i & (1<<j) ? "1" : "0");
                puts("");
            }
        }
        if(T) puts("");
    }
    return 0;
}
