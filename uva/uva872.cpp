//topsort
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
bool ok;
char c[20];
map<char, int> m;
vector<int> v[20];
int pre[20], ans[20];

void init(){
    char tmp[205] = {0}, ign, a, b;
    char *cptr;
    m.clear();
    ok = false;
    getchar();
    gets(tmp);
    cptr = tmp;
    //puts(tmp);
    for(n = 0; sscanf(cptr, "%c", &c[n]) == 1; n++, cptr+=2){
       // printf("%c", c[n]);
        v[n].clear();
        pre[n] = 0;
    }//puts("");
    sort(c, c+n);
    for(int i=0; i<n; i++)
        m[c[i]] = i;
    gets(tmp);
    tmp[strlen(tmp)] = 0;
    cptr = tmp;
    //puts(tmp);
    while(sscanf(cptr, "%c<%c", &a, &b) == 2){
        v[m[a]].push_back(m[b]);
        pre[m[b]]++;
        cptr+=4;
    }
}

void sol(int st){
    if(st == n){
        //print
        for(int i=0; i<n; i++){
            if(i) printf(" ");
            printf("%c", ans[i]);
        }
        puts("");
        ok = true;
    }
    //printf("%d\n", st);
    int now = -1;
    for(int i=0; i<n; i++)
        if(!pre[i]){
            now = i;
            ans[st] = c[i];
            pre[i] = -1;
            for(int j = 0; j<v[i].size(); j++)
                pre[ v[i][j] ]--;
            sol(st+1);
            pre[i] = 0;
            for(int j = 0; j<v[i].size(); j++)
                pre[ v[i][j] ]++;
        }
}

int main(){
    int T;
    freopen("t.in", "r", stdin);
    scanf("%d", &T);
    getchar();
    while(T--){
        init();
        //printf("%d---\n", n);
        sol(0);
        if(!ok) puts("NO");
        if(T) puts("");
    }
    return 0;
}
