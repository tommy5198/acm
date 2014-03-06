#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<map>
using namespace std;

int n, m;
bool alc[100][100];
int vis[100];
bool root[100];
string name[100];
map<string, int> id;
vector<string> ans;
void topsort(int now){
    if(vis[now] == 1) return ;
    vis[now] = 1;
    printf("%d ", now);
    for(int i=0; i<n; i++)
        if(alc[now][i] && vis[i] == 0)
            topsort(i);
    vis[now] = 2;
    ans.push_back(name[now]);
}
int main(){
    int T = 1;
    freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) != EOF){
        ans.clear();
        for(int i=0; i<n; i++){
            cin>>name[i];
            for(int j=0; j<i; j++){
                alc[j][i] = true;
                alc[i][j] = false;
            }
            id[name[i]] = i;
            vis[i] = 0;
            root[i] = true;
        }
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            string t, tt;
            cin>>t>>tt;
            int a = id[t], b = id[tt];
            root[b] = false;
            alc[a][b] = true;
            alc[b][a] = false;
        }
        for(int i=0; i<n; i++)
        if(root[i]){
            topsort(i);
            printf("----==\n");
            break;
        }
        for(int i=ans.size()-1; i>=0; i--)
            printf("%s ", ans[i].c_str());
        printf("\n");
    }
    return 0;
}
