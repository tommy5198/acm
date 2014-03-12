//topsort
//uva cant use sync_with_stdio
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

int n, m;
string drink[100];
map<string, int> mp;
vector<int> alc[100];
int pre[100];

bool init(){
    char cstr[51];
    string a, b;
    if(scanf("%d", &n) == EOF)
        return false;
    mp.clear();
    for(int i=0; i<n; i++){
        scanf("%s", cstr);
        drink[i] = cstr;
        mp[drink[i]] = i;
        pre[i] = 0;
        alc[i].clear();
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%s", cstr); a = cstr;
        scanf("%s", cstr); b = cstr;
        alc[ mp[a] ].push_back(mp[b]);
        pre[mp[b]]++;
    }
    return true;
}
void sol(int T){
    printf("Case #%d: Dilbert should drink beverages in this order:", T);
    for(int cnt=0; cnt<n; cnt++){
        int now = -1;
        for(int i=0; i<n; i++)
            if(!pre[i]){
                now = i; break;
            }
        pre[now] = -1;
        //memset(vis, false, sizeof(vis));
        //dfs(now);
        for(int i=0; i<alc[now].size(); i++)
            pre[alc[now][i]]--;
        printf(" %s", drink[now].c_str());
    }
    puts(".\n");
}
int main(){
    //ios_base::sync_with_stdio(false);
    //freopen("t.in", "r", stdin);
    for(int i=1; init(); i++)
        sol(i);
    return 0;
}
