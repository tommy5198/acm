#include<cstdio>
#include<cstring>

int n, m;
int h[100], g[100];
double gx[100], gy[100], hx[100], hy[100];
double s, v;
bool e[100][100];
bool vis[100];

bool init(){
    if(scanf("%d%d%lf%lf", &n, &m, &s, &v) == EOF)
        return false;
    for(int i=0; i<n; i++){
        g[i] = -1;
        scanf("%lf%lf", gx+i, gy+i);
    }

    for(int i=0; i<m; i++){
        h[i] = -1;
        scanf("%lf%lf", hx+i, hy+i);
    }

    return true;
}

double dis(int a, int b){
    return (gx[a]-hx[b])*(gx[a]-hx[b]) + (gy[a]-hy[b])*(gy[a]-hy[b]);
}

bool dfs(int now){
    for(int i=0; i<m; i++)
        if(!vis[i] && h[i] != now && e[now][i]){
            vis[i] = true;
            if(h[i]<0 || dfs(h[i])){
                g[now] = i;
                h[i] = now;
                return true;
            }
        }
    return false;
}

void sol(){
    int ans = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            e[i][j] = dis(i, j) <= s*v*s*v;
            if(e[i][j] && g[i]<0 && h[j]<0){
                g[i] = j; h[j] = i;
            }
        }

    for(int i=0; i<n; i++)
        if(g[i]<0){
            memset(vis, false, sizeof(bool)*m);
            if(!dfs(i))
                ans++;
        }
    
    printf("%d\n", ans);
}

int main(){
    while(init())
        sol();
    return 0;
}
