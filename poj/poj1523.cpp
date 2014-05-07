// cut vectex
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 1000

int k, dpt, mx, T = 1;
int dfn[MAX], low[MAX];
bool e[MAX][MAX];
int cut[MAX];

bool init(){
    int a, b;
    scanf("%d", &a);
    if(!a) return false;

    memset(e, false, sizeof(e));
    
    do{
        mx = mx>a ? mx : a;
        scanf("%d", &b);
        mx = mx>b ? mx : b;
        e[a][b] = e[b][a] = true;
        scanf("%d", &a);
    }while(a);
    
    memset(dfn, 0, sizeof(int)*(mx+1));
    memset(low, 0, sizeof(int)*(mx+1));
    dpt = 0; k = 0;
    return true;
}

void dfs(int nw, int p){
    int kid = 0;
    cut[nw] = p ? 0 : -1;
    dfn[nw] = low[nw] = ++dpt;
    for(int i=1; i<=mx; i++)
        if(e[nw][i]){
            if(!dfn[i]){
                dfs(i, nw);
                kid++;
                if(dfn[nw]<=low[i]) cut[nw]++;
                low[nw] = low[nw]<low[i] ? low[nw] : low[i];
            }else if(i != p)
                low[nw] = low[nw]<dfn[i] ? low[nw] : dfn[i];
        }
    if((kid>1 || p) && cut[nw]>0)
        k = 1;
}

void sol(){
    for(int i=1; i<=mx; i++)
        if(!dfn[i])
            dfs(i, 0);
    printf("Network #%d\n", T++);
    if(!k)
        puts("  No SPF nodes\n");
    else{
        for(int i=1; i<=mx; i++)
            if(cut[i]>0)
                printf("  SPF node %d leaves %d subnets\n", i, cut[i]+1);
        puts("");
    }
}

int main(){
    while(init())
        sol();
    return 0;
}
