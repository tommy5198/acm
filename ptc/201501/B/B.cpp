#include<cstdio>
#include<cstring>

int nx, ny;             // X的點數目、Y的點數目
int mx[1000], my[1000];   // X各點的配對對象、Y各點的配對對象
bool vy[1000];           // 紀錄Graph Traversal拜訪過的點
bool adj[1000][1000];     // 精簡過的adjacency matrix

// 以DFS建立一棵交錯樹
bool DFS(int x)
{
    for (int y=0; y<ny; ++y)
        if (adj[x][y] && !vy[y])
        {
            vy[y] = true;

            // 找到擴充路徑
            if (my[y] == -1 || DFS(my[y]))
            {
                mx[x] = y; my[y] = x;
                return true;
            }
        }
    return false;
}

int bipartite_matching()
{
    // 全部的點初始化為未匹配點。
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));

    // 依序把X中的每一個點作為擴充路徑的端點，
    // 並嘗試尋找擴充路徑。
    int c = 0;
    for (int x=0; x<nx; ++x)
//      if (mx[x] == -1)    // x為未匹配點，這行可精簡。
        {
            // 開始Graph Traversal
            memset(vy, false, sizeof(vy));
            if (DFS(x)) c++;
        }
    return c;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        int k;
        scanf("%d%d%d", &nx, &ny, &k);
        memset(adj, false, sizeof(adj));
        for(int i=0; i<k; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a-1][b-1] = true;
        }
        printf("%d\n", nx+ny-bipartite_matching());
    }
    return 0;
}
