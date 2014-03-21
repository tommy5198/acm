#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int h, w, x, y;
char grid[20][20];
char kid[2][20000];
int len[2];

void init(){
    scanf("%d%d", &h, &w);
    getchar();
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++)
            grid[i][j] = getchar();
        getchar();
    }
    puts("=");
    for(int k=0; k<2; k++){
        scanf("%d%d%d", &len[k], &x, &y);
        getchar();
        x--; y--;
        kid[k][0] = grid[x][y];
        for(int i=1; i<=len[k]; i++){
            char dir = getchar();
            switch(dir){
                case 'N': x++; break;
                case 'S': x--; break;
                case 'E': y++; break;
                case 'W': y--; break;
            }
            kid[k][i] = grid[x][y];
        }
    }
}



int LCS(int k){

    vector<int> p[128], v;
    for(int i=0; i<len[k^1]; i++)
        p[kid[k^1][i]].push_back(i);
    v.push_back(-1);
    for(int i=0; i<len[k]; i++)
        for(int j=p[kid[k][i]].size()-1; j>=0; j--){
            int n = p[kid[k][i]][j];
            if(n > v.back()) v.push_back(n);
            else *lower_bound(v.begin(), v.end(), n) = n;
        }
    return v.size()-1;
}
void sol(int T){
    /*
    for(int i=0; i<=len[0]; i++)
        dp[0][i] = 0;
    for(int i=0; i<=len[1]; i++)
        dp[i][0] = 0;
    for(int i=1; i<=len[0]; i++)
        for(int j=1; j<=len[1]; j++)
            if(kid[0][i-1] == kid[1][j-1]) dp[i][j] = dp[i][j] + 1;
            else dp[i][j] = dp[i-1][j]>dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
    */
    int lcs = LCS(len[0]>len[1]);
    printf("Case %d: %d %d\n", T, len[0]-lcs, len[1]-lcs);
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        sol(i);
    }
    return 0;
}
