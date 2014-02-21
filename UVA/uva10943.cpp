#include<iostream>
#include<cstring>
using namespace std;



int main(){

    int n,k;
    int dp[101][101];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<101;i++)
        dp[1][i]=1;
    for(int i=2;i<101;i++)
        for(int j=0;j<101;j++){
            for(int x=j;x>=0;x--)
                dp[i][j]+=dp[i-1][x];
            dp[i][j]%=1000000;
        }
    while(cin>>n>>k,n)
        cout<<dp[k][n]<<endl;
    return 0;
}
