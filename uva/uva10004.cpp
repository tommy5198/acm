#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int n;
vector<int> v[200];
int st[200];

bool DFS(int now, int nst){
    st[now] = nst;
    for(int i=0; i<v[now].size(); i++){
        if(st[v[now][i]] == nst)
            return false;
        else if(st[v[now][i]] == 0 && !DFS(v[now][i], -nst))
            return false;
    }
    return true;
}
int main(){
    while(scanf("%d", &n)!=EOF, n){
        for(int i=0; i<n; i++)
            v[i].clear();
        memset(st, 0, sizeof(st));
        int L, x, y;
        scanf("%d", &L);
        while(L--){
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }

        if(DFS(0, 1))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
