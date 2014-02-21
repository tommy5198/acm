#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int vil[10001][10001];
int n,md,td,mv;
bool vis[10001];


void dfs(int now){
    vis[now]=true;

    for(int i=0;i<n;i++){
        if(!vis[i] && vil[now][i]){
            td+=vil[now][i];
            dfs(i);
            td-=vil[now][i];
        }
    }
    if(md<td){
        mv=now;
        md=td;
    }
}

int main(){
    
    int a,b,d;
    string str;
    while(getline(cin,str)){
        if(str.size()<3){
            n++;
            md=0;
            td=0;
            dfs(1);
            memset(vis,0,sizeof(vis));
            dfs(mv);
            cout<<md<<endl;
            memset(vis,0,sizeof(vis));
            memset(vil,0,sizeof(vil));
            continue;
        }
        sscanf(str.c_str(),"%d %d %d",&a,&b,&d);
        vil[a][b] = vil[b][a] = d;
        n=max(n,a);
        n=max(n,b);
    }
    n++;
    md=0;
    td=0;
    dfs(1);
    memset(vis,0,sizeof(vis));
    dfs(mv);
    cout<<md<<endl;
    return 0;
}
