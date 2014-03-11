//DFS
#include<cstdio>
#include<vector>
using namespace std;

int n, m, ans;
int task[100];
vector<int> v[100];
bool root[100];

bool init(){
    if(scanf("%d", &n) == EOF)
        return false;
    ans = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &task[i]);
        v[i].clear();
        root[i] = true;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a-1].push_back(b-1);
        root[b-1] = false;
    }
    return true;
}
void dfs(int now, int day){
    ans = ans>day ? ans : day;
    for(int i=0; i<v[now].size(); i++)
        dfs(v[now][i], day+task[v[now][i]]);
}
void sol(){
    for(int i=0; i<n; i++)
        if(root[i])
            dfs(i, task[i]);
    printf("%d\n", ans);
}
int main(){
    while(init())
        sol();
    return 0;
}
