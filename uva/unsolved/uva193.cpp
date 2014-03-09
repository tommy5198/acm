#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
vector<int> v[101], b;
int color[101];
bool vis[101];
int ans[100];
int sum;
void init(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++){
        v[i].clear();
        color[i] = 0;
    }
    sum = 0;
    for(int i=0; i<k; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void btrack(int now, int d, int bsum){

    color[now] = 1;
    int cnt = 0;
    for(int i=0; i<v[now].size(); i++){
        if(!color[v[now][i]]) cnt++;
            color[v[now][i]] = 2;
    }
    for(int i=1; i<n; i++)
        if(!color[i])
            btrack(i, d+1+cnt, bsum+1);

}

int main(){
    int m;
    freopen("t.in", "r", stdin);
    scanf("%d", &m);
    while(m--){
        init();
        btrack(0, 0);
        printf("%d\n%d", sum, ans[0]);
        for(int i=1; i<sum; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
