#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
#define INF 100000000

map<string, vector<string> > leg;
//vector<string> W;
map<string, int> visited;
int sum;

void DFS(string src, string dst, int s){

    visited[src] = s;
    for(int i=0; i<leg[src].size(); i++){
        if(leg[src][i] == dst && s < sum)
            sum = s;
        else if(visited[leg[src][i]] == 0 || visited[leg[src][i]] > s+1)
            DFS(leg[src][i], dst, s+1);
    }

}
int main(){
    int ca;
    scanf("%d", &ca);
    printf("SHIPPING ROUTES OUTPUT\n");
    for(int c=1; c<=ca; c++){
        printf("\nDATA SET %2d\n\n", c);

        int s, m, n, p;
        string t, tmp;
        leg.clear();

        scanf("%d%d%d", &m, &n, &p);
        while(m--)
            cin>>tmp;
        while(n--){
            cin>>tmp>>t;
            leg[tmp].push_back(t);
            leg[t].push_back(tmp);
        }
        while(p--){
            cin>>s>>tmp>>t;
            sum = INF;
            visited.clear();
            DFS(tmp, t, 1);
            if(sum != INF)
                printf("$%d\n", sum*s*100);
            else
                printf("NO SHIPMENT POSSIBLE\n");
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
