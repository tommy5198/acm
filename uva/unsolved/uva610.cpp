#include<cstdio>

int n, m, dpt, T;
int ep[1000], dfn[1000], low[1000];
int e[1000][1000];
bool vis[1000], iscut[1000];

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;
    for(int i=0; i<n; i++){
        ep[i] = dfn[i] = low[i] = 0;
        vis[i] = iscut[i] = false;
    }
    dpt = 0;
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        e[a][ep[a]++] = b;
        e[b][ep[b]++] = a;
    }
    return true;
}

void dfs(int nw, int p){
       
    dfn[nw] = low[nw] = ++dpt;
    for(int i=0; i<ep[nw]; i++){
        int nt = e[nw][i];
        if(!dfn[nt]){
            dfs(nt, nw);
            if(dfn[nw]<=low[nt]) 
                iscut[nw] = true;
            low[nw] = low[nw]<low[nt] ? low[nw] : low[nt];
        }else if(i != p)
            low[nw] = low[nw]<dfn[nt] ? low[nw] : dfn[nt];
    }
    if(dfn[nw] == dpt-1)
        iscut[nw] = true;
}

void road(int nw){
    
    vis[nw] = true;
    for(int i=0; i<ep[nw]; i++){
        int nt = e[nw][i];
        if(vis[nt]) continue;
        if(!iscut[nw] || !iscut[nt])
            printf("%d %d\n", nw+1, nt+1);
        road(nt);
    }

}

void sol(){
    printf("%d\n\n", T++);
    for(int i=0; i<n; i++)
        if(!dfn[i])
            dfs(i, -1);
    for(int i=0; i<n; i++){
        if(!vis[i])
            road(i);
    }
    for(int i=0; i<n; i++)
        if(iscut[i])
            for(int j=0; j<ep[i]; j++){
                int nt = e[i][j];
                if(iscut[nt])
                    printf("%d %d\n%d %d\n", i+1, nt+1, nt+1, i+1);
            }
            
    puts("#");
}

int main(){
    T = 1;
    while(init())
        sol();
    return 0;
}
