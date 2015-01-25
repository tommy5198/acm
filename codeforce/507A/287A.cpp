#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct instr{
    int id, day;
    bool operator<(const instr &t)const{
        return day<t.day;
    }
};

instr adj[101];
int ans[101];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {
        scanf("%d", &adj[i].day);
        adj[i].id = i;
    }
    sort(adj+1, adj+n+1);
    int i;
    for(i=0; i<n && k; i++) {
        if(adj[i+1].day > k)
            break;
        ans[i] = adj[i+1].id;
        k -= adj[i+1].day;
    }
    printf("%d\n", i);
    for(int j=0; j<i; j++)
        printf("%d ", ans[j]);
    return 0;
}
