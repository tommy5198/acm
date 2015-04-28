#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int sig;
bool adj[1001][1001];
int n, m;
bool visited[1001];
vector<int> v;
int ans;

void dfs(int now){

    visited[now] = true;
    for(int i = 1; i <= n; i++){
        if(adj[now][i] && !visited[i]){
            dfs(i);
        }
    }
    v.push_back(now);
}

void sdfs(int now){

    visited[now]=true;
    for(int i = 1; i <= n; i++){
        if(adj[i][now] && !visited[i]){
            sdfs(i);
        }
    }
    
}

void find_ssc(){

    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i);

    memset(visited, 0, sizeof(visited));

    for(int i = v.size()-1; i >= 0; i--){
        if(!visited[v[i]]){
            sdfs(v[i]);
            ans++;
        }
    }
}

int main(){
    int ca,t;
    while(cin>>ca){
        
        while(ca--){
            cin>>n>>m;
            memset(adj, 0, sizeof(adj));
            memset(visited, 0, sizeof(visited));
            ans = 0;
            v.clear();

            for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                adj[a][b]=true;
            }
            find_ssc();
            cout<<ans<<endl;
            cin>>t;
        }
        if(t == -1)
            break;
    }
    return 0;
}
