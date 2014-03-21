#include<cstdio>
#include <utility>
#include<stack>
#include<cstring>
using namespace std;

int n, m;
int mat[100][100], dp[100];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", mat[i]+j);
}

int mx1d(){
    int mx = 0, tmp = 0;
    for(int i=0; i<n; i++){
        if(tmp >= 0) tmp += dp[i];
        else tmp = dp[i];
        mx = mx>tmp ? mx : tmp;
    }
    return mx;
}
void sol(){
    /*
    //puts("");
    //printf("====\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]) dp[i][j] = i==0 ? 1 : dp[i-1][j]+1;
            else dp[i][j] = 0;
           // printf("%d", dp[i][j]);
        }
       // puts("");
    }

    int mx = 0;
    for(int i=n-1; i>=0; i--){
        stack<pair<int, int> > stk;
        for(int j=0; j<n; j++){
            if(stk.empty() && dp[i][j]){
                    stk.push(make_pair(dp[i][j], j));
                    //printf("%d %d %d=00.0.=\n", i, j, stk.top().second);
            }
            if(!stk.empty() && dp[i][j] < stk.top().first || !dp[i][j]){
                int pre;
                //if(!stk.empty()) printf("%d %d %d==\n", i, j, stk.top().second);
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
    */
    int mx = 0;
    for(int i=0; i<n; i++){
       memset(dp, 0, sizeof(dp));
        for(int j=i; j<n; j++){
            for(int k=0; k<n; k++)
                dp[k] += mat[j][k];
            mx = max(mx, mx1d());
        }
    }
    printf("%d\n", mx);
}
int main(){
    //freopen("t.in", "r", stdin);
    init();
    sol();
    return 0;
}
