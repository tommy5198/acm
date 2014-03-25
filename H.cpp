#include<cstdio>

int main(){
    int T, n;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        scanf("%d", &n);
        int cnt = 0, i, ans = 0;
        for(i=1; i<=n; i++){
            getchar();
            char c = getchar();
            if(ans) continue;
            if(c == 'W') cnt = 0;
            else cnt++;
            if(cnt == 3)
                ans = i;
        }
        if(ans)
            printf("Case %d: %d\n", t, ans);
        else
            printf("Case %d: Yay! Mighty Rafa persists!\n", t);
    }
    return 0;
}
