#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
bool a[25][25];

int DFS(int st){
    int d = 0;
    bool leaf = true;
    for(int i=0; i<n; i++)
        if(a[st][i]){
            leaf = false;
            a[st][i] = a[i][st] = false;
            d = max(d, DFS(i));
            a[st][i] = a[i][st] = true;
        }
    return leaf ? 0 : d+1;
}
int main(){
    while(scanf("%d%d", &n, &m), n&&m){
        int s, t, mx = -1;
        memset(a, false, sizeof(a));
        for(int i=0; i<m; i++){
            scanf("%d%d", &s, &t);
            a[s][t] = a[t][s] = true;
        }
        for(int i=0; i<n; i++)
            mx = max(mx, DFS(i));
        printf("%d\n", mx);
    }
    return 0;
}
