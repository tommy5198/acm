#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int nt, z;
    bool operator<(const node &t)const{
        return z<t.z;
    }
}tmp, next, nxt;

vector<node> e[51];
int n, m, mi, midx;
int zip[51];
priority_queue<node> pq;
bool vis[51] = {false};

void init(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        e[i].clear();
        scanf("%d", zip+i);
    }
    for(int j=0; j<m; j++){
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        tmp.nt=y; tmp.z = zip[y];
        e[x].push_back(tmp);
        tmp.nt=x; tmp.z = zip[x];
        e[y].push_back(tmp);
    }
    mi = 10000000;
    for(int i=0; i<n; i++){
        if(zip[i]<mi){
            mi = zip[i];
            midx = i;
        }
        vis[i] = false;
        sort(e[i].begin(), e[i].end());
    }
}

/*
void sol(){
    bool vis[51] = {false};
    for(int i=0; i<e[midx].size(); i++){
        nxt = e[midx][i];
        pq.push(nxt);
        vis[nxt.nt] = true;
    }
    printf("%d", zip[midx]);
    vis[midx] = true;
    while(!pq.empty()){
        next = pq.top();
        pq.pop();
        printf("%d", next.z);
        for(int i=0; i<e[next.nt].size(); i++){
            nxt = e[next.nt][i];
            if(!vis[nxt.nt]){
                pq.push(nxt);
                vis[nxt.nt] = true;
            }
        }
    }
}
*/

void sol(int nw){
    
    for(int i=0; i<e[nw].size(); i++){
        next = e[nw][i];
        if(!vis[next.nt]){
            vis[next.nt] = true;
            printf("%d", next.z);
            sol(next.nt);
        }
    }
    
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        printf("Case #%d: ", i);
        vis[midx] = true;
        printf("%d", zip[midx]);
        sol(midx);
        puts("");
    }
    return 0;
}
