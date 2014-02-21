#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
#define MAXN 300
#define INF 10000000
using namespace std;

int dir[MAXN][MAXN],opp[MAXN][MAXN];
int v;
int max_flow(int source,int target){
    
    int i,now,next,minf,p[MAXN],MAX_flow=0;
    bool visited[MAXN]={false};
    queue<int> bfs;
    while(1){
        memset(visited,false,sizeof(visited));
        while(!bfs.empty()) 
            bfs.pop();
        bfs.push(source);
        visited[source]=true;
        while(!bfs.empty()){
            now = bfs.front();
            for(next=0;next<v;next++){
                
                if(visited[next]) continue;
                if(dir[now][next]-opp[now][next]>0){
                    p[next]=now;
                    visited[next]=true;
                    bfs.push(next);
                }else if(opp[next][now]>0){
                    p[next]=-now;
                    visited[next]=true;
                    bfs.push(next);
                }
            }
            bfs.pop();
        }
        if(!visited[target]) break;

        for(i=target,minf=INF;i!=source;i=abs(p[i])){
            if(p[i]>=0) 
                minf=min(minf,dir[p[i]][i]-opp[p[i]][i]);
            else
                minf=min(minf,opp[i][-p[i]]);
        }
        for(i=target;i!=source;i=abs(p[i])){
            if(p[i]>=0) 
                opp[p[i]][i]+= minf;
            else
                opp[i][-p[i]]-=minf;
        }
    }
    for(i=0;i<v;i++)
        MAX_flow+=opp[source][i];
    return MAX_flow;

}


int main(){
    
    int count=1;
    while(cin>>v && v){
        int s,d,e;
        cin>>s>>d>>e;
        memset(dir,0,sizeof(dir));
        memset(opp,0,sizeof(opp));
        for(int i=0;i<e;i++){
            int t,tt,value;
            cin>>t>>tt>>value;
            t--;
            tt--;
            dir[t][tt]+=value;
            dir[tt][t]+=value;
        }
        int mflow=max_flow(s,d);
        cout<<"Network "<<count++<<endl<<"The bandwidth is "<<mflow<<"."<<endl<<endl;


    }
    return 0;
}
