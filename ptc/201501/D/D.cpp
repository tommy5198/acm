#include<cstdio>

int n;
int m[5000][5000];
int main(){
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%1d", m[i]+j);
        int ans = -1;
        for(int i=0; i<n && ans == -1; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && (m[i][j] || !m[j][i]) )
                    break;
                else if(j == n-1) {
                    ans = i+1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
