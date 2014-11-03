#include<cstdio>
#include<algorithm>
using namespace std;

#define min(a, b) (a)>(b)?(b):(a)
#define INF 2e9
int main(){
    int T, ca = 1;
    scanf("%d", &T);
    while(T--){
        int n, m;
        int num[100];
        int gp[100][100];

        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++){
            scanf("%d", num+i);
            for(int j=0; j<m; j++)
                gp[i][j] = INF;
        }
        sort(num, num+n);
        for(int i=0; i<n; i++){
            gp[i][0] = num[i] - num[0];
            for(int j=0; j<i; j++){
                for(int k=0; k<=j && k<m-1; k++){
                    gp[i][k+1] = min(gp[i][k+1], gp[j][k] + num[i] - num[j+1]);
                }
            }
        }
        printf("Case #%d: %d\n", ca++, gp[n-1][m-1]);
    }
    return 0;
}
