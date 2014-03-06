#include<cstdio>
#include<vector>
using namespace std;
int n, k;
vector<int> v[101], b;
int color[101];
bool DFS(int now, int nowc){
    int nextc = nowc==1?2:1;
    color[now] = nowc;
    printf("%d %d", now, nowc);
    for(int i=0; i<v[now].size(); i++){
        if(color[v[now][i]] == 1 || color[v[now][i]] == 0 && !DFS(v[now][i], nextc) ){
            color[now] = 0;
            return false;
        }
    }
    return true;
}
void init(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++){
        v[i].clear();
        color[i] = 0;
    }
    b.clear();
    for(int i=0; i<k; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        init();
        for(int i=1; i<n; i++){
            if(!color[i]){
                int tmp = DFS(i, 0);

            }
        }
        printf("%d\n%d", b.size(), b[0]);
        for(int i=1; i<b.size(); i++)
            printf(" %d", b[i]);
        printf("\n");
    }
    return 0;
}
