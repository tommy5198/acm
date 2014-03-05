#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
vector<int> road[2];
bool con[1001][1001];
int dfn[1001];
int low[1001];
int dpt;
bool visited[1001];

void dfnlow(int u,int p){

    dfn[u]=low[u]=++dpt;
    for(int w=1;w<=n;w++){
        if(con[u][w]){
            if(!dfn[w]){
                dfnlow(w,u);
                low[u]=min(low[u],low[w]);
            }else if(w!=p)
                low[u]=min(low[u],low[w]);
        }
    }
}

void find_b(int now){

    visited[now]=true;

    for(int i=1;i<=n;i++){

        if(con[now][i]){
            con[i][now] = false;
            road[0].push_back(now);
            road[1].push_back(i);
            if(low[now] != low[i]){
                road[0].push_back(i);
                road[1].push_back(now);
            }
            if(!visited[i])
                find_b(i);
        }
    }

}
int main(){

    int ca=1;
    while(cin>>n>>m,n){
        memset(con,0,sizeof(con));
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        memset(visited,0,sizeof(visited));
        dpt=0;
        road[0].clear();
        road[1].clear();
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            con[a][b] = con[b][a] = true;
        }
        dfnlow(1,-1);
        find_b(1);
        cout<<"__________________"<<endl;
        for(int i=1;i<=n;i++)
            cout<<i<<" "<<low[i]<<endl;
        cout<<"------------"<<endl;
        cout<<ca++<<endl<<endl;
        for(int i=0;i<road[0].size();i++)
            cout<<road[0][i]<<" "<<road[1][i]<<endl;
        cout<<"#"<<endl;
    }
    return 0;
}
