// WTF AC?

#include<cstdio>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

map<int,vector<int> > node;
map<int,int> used;
map<int,bool> exist;
int loot;

void dfs(int a, int b){
    //printf("%d ", a);
    used[a] = b;

    if(b == 0)
        return ;
    for(int i=0; i<node[a].size(); i++)
        if(used[node[a][i]] < b-1 && node[a][i] != loot)
            dfs(node[a][i], b-1);
    return ;
}

int main(){
    int n, c=1;
    while(cin>>n, n!=0){
        int a,b;
        exist.clear();
        node.clear();
        for(int i=0; i<n; i++){
            cin>>a>>b;
            node[a].push_back(b);
            node[b].push_back(a);
            exist[a] = true;
            exist[b] = true;
        }
        while(cin>>a>>b, a!=0||b!=0){
            loot = a;
            exist[a] = true;
            dfs(a, b);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", c++, exist.size()-used.size(), a, b);
            used.clear();
        }
    }

    return 0;
}
