#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
bool con[101][101];
int dfn[101];
int low[101];
int dpt;
int ans;
void dfs(int now,int p){
    int kid=0;
    bool cut=false;
    dfn[now] = low[now] = ++dpt;
    for(int i=1;i<=n;i++){
        if(con[now][i]){
            if(!dfn[i]){
                dfs(i,now);
                kid++;
                if(dfn[now]<=low[i]) cut=true;
                low[now]=min(low[now],low[i]);
            }else if(i!=p)
                low[now]=min(low[now],dfn[i]);
        }
    }
    if((kid>1||p!=-1)&&cut) ans++;

}

int main(){

    while(cin>>n,n){
        memset(con,0,sizeof(con));
        char str[100];
        while(gets(str)){
            if(str[0]=='0')
                break;
            int st=0,td;
            for(char *pch=strtok(str," ");pch;pch=strtok(NULL," ")){
                if(!st){
                    sscanf(pch,"%d",&st);
                    continue;
                }
                sscanf(pch,"%d",&td);
                con[st][td] = con[td][st] = true;
            }
        }
        ans=0;
        dpt=0;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        dfs(1,-1);
        cout<<ans<<endl;
    }
    return 0;
}
