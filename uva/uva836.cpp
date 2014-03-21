//DP
#include<cstdio>
#include <utility>
#include<stack>
#include<cstring>
using namespace std;

int n, m;
int mat[25][25], dp[25][25];

void init(){
    char c[26];
    n = 0;
    while(gets(c) && c[0]){
        for(int i=0; c[i]; i++){
            mat[n][i] = c[i]-'0';
            //if(!mat[n][i]) mat[n][i] = -100000000;
        }
        n++;
    }
}
/*  max subarray
int mx1d(){
    int mx = 0, tmp = 0;
    for(int i=0; i<n; i++){
        if(tmp >= 0) tmp += dp[i];
        else tmp = dp[i];
        mx = mx>tmp ? mx : tmp;
    }
    return mx;
}*/
void sol(){

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(mat[i][j]) dp[i][j] = i==0 ? 1 : dp[i-1][j]+1;
            else dp[i][j] = 0;
        }

    int mx = 0;
    for(int i=n-1; i>=0; i--){
        stack<pair<int, int> > stk;
        for(int j=0; j<n; j++){
            if(stk.empty() && dp[i][j])
                stk.push(make_pair(dp[i][j], j));
            if(!stk.empty() && dp[i][j] < stk.top().first || !dp[i][j]){
                int pre;
                while(!stk.empty() && dp[i][j] < stk.top().first){
                    mx = max(mx, stk.top().first*(j-stk.top().second));
                    pre = stk.top().second;
                    stk.pop();
                }
                if(dp[i][j]) stk.push(make_pair(dp[i][j], pre));
            }else if(!stk.empty() && dp[i][j] > stk.top().first) stk.push(make_pair(dp[i][j], j));
            if(j == n-1)
                while(!stk.empty()){
                    mx = max(mx, stk.top().first*(j-stk.top().second+1));
                    stk.pop();
                }
        }
    }

    /*  max subarray
    int mx = 0;
    for(int i=0; i<n; i++){
       memset(dp, 0, sizeof(dp));
        for(int j=i; j<n; j++){
            for(int k=0; k<n; k++)
                dp[k] += mat[j][k];
            mx = max(mx, mx1d());
        }
    }
    */
    printf("%d\n", mx);
}
int main(){
    //freopen("t.in", "r", stdin);
    int T;


    while(scanf("%d", &T) != EOF){
        getchar();
        getchar();
        while(T--){
            init();
            sol();
            if(T) puts("");
        }
    }
    return 0;
}
