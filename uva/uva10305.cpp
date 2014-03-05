#include<cstdio>
#include<vector>
using namespace std;

vector<int> v[100];
int exed[100];
int ans[100];
bool root[100];
int np;
void topsort(int now){
   if(exed[now] == 1) return;
   exed[now] = 1;

   for(int i=0; i<v[now].size(); i++)
       if(exed[v[now][i]] != 2)
           topsort(v[now][i]);
   exed[now] = 2;
   ans[np--] = now;
}
int main(){
    
    int n, m;
    while(scanf("%d%d", &n, &m), n||m){
        int x, y;
        np = n - 1;
        for(int i=1; i<=n; i++){
            v[i].clear();
            root[i] = true;
            exed[i] = 0;
        }
        for(int i = 0; i<m; i++){
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            root[y] = false;
        }
        for(int i=1; i<=n; i++)
            if(root[i])
                topsort(i);
        printf("%d", ans[0]);
        for(int i=1; i<n; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
