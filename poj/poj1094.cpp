#include<cstdio>
#include<vector>
using namespace std;

int n, m, ok;
char c[27], ans[27];
vector<int> v[27];
int pre[27];

void sol(int st){
    if(st == n){
        ok++;
        ans[st] = 0;
        return ;
    }
    //printf("%d\n", st);
    int now = -1;
    for(int i=0; i<n; i++)
        if(!pre[i]){
            now = i;
            ans[st] = c[i];
            pre[i] = -1;
            for(int j=0; j<v[i].size(); j++)
                pre[ v[i][j] ]--;
            sol(st+1);
            pre[i] = 0;
            for(int j=0; j<v[i].size(); j++)
                pre[ v[i][j] ]++;
            if(ok>1) return;
        }
}

int main(){
    freopen("t.in", "r", stdin);
    while(scanf("%d%d", &n, &m), n||m){
        char str[4], a, b;
        for(int i=0; i<n; i++){
            v[i].clear();
            pre[i] = 0;
            c[i] = i + 'A';
        }
        ok = 0;
        for(int i=1; i<=m; i++){
            //scanf("%s", str);
            getchar();
            scanf("%c<%c", &a, &b);
            v[a-'A'].push_back(b-'A');
            pre[b-'A']++;
            if(ok) continue;
            if(i >= n-1){
                sol(0);
            if(ok == 1)
                ok = i;
            else if(!ok)
                ok = -i;
            else
                ok = 0;
            }
        }
        if(!ok)
            puts("Sorted sequence cannot be determined.");
        else if(ok>0)
            printf("Sorted sequence determined after %d relations: %s.\n", ok, ans);
        else
            printf("Inconsistency found after %d relations.\n", -ok);
    }
    return 0;
}
