#include<iostream>

using namespace std;

int main(){

    int n,m;
    int adj[103][103];
    int dp[103][103];
    stack<int> stk;
    while(cin>>n>>m,n){
        memset(adj,-1,sizeof(adj));
        memset(dp,0,sizeof(dp));
        stk.clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>adj[i][j];
                dp[i][j] = adj[i][j]^1;
            }

        for(int i=1;i<=m;i++)
            for(int j=2;j<=n;j++)
                if(dp[j-1][i]>0)
                    dp[j][i] = dp[j-1][i] + 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(stk.empty() || dp[i][j] > stk.top())
        }

