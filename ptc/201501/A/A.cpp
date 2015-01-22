#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int X = 1000;   // X的點數目，等於Y的點數目
const int Y = 1000;   // Y的點數目
int adj[X][Y];      // 精簡過的adjacency matrix
int lx[X], ly[Y];   // vertex labeling
int mx[X], my[Y];   // X各點的配對對象、Y各點的配對對象
int q[X], *qf, *qb; // BFS queue
int p[X];           // BFS parent，交錯樹之偶點，指向上一個偶點
bool vx[X], vy[Y];  // 紀錄是否在交錯樹上
int dy[Y], pdy[Y];  // DP表格
 int n;
// relaxation
void relax(int x)
{
    for (int y=0; y<n; ++y)
        if (adj[x][y] != 1e9)
            if (lx[x] + ly[y] - adj[x][y] < dy[y])
            {
                dy[y] = lx[x] + ly[y] - adj[x][y];
                pdy[y] = x; // 紀錄好是從哪個樹葉連出去的
            }
}

// 調整交錯樹上的label、調整DP表格
void reweight()
{
    int d = 1e9;
    for (int y=0; y<n; ++y) if (!vy[y]) d = min(d, dy[y]);
    for (int x=0; x<n; ++x) if ( vx[x]) lx[x] -= d;
    for (int y=0; y<n; ++y) if ( vy[y]) ly[y] += d;
    for (int y=0; y<n; ++y) if (!vy[y]) dy[y] -= d;
}

// 擴充路徑
void augment(int x, int y)
{
    for (int ty; x != -1; x = p[x], y = ty)
    {
        ty = mx[x]; my[y] = x; mx[x] = y;
    }
}

// 延展交錯樹：使用既有的等邊
bool branch1()
{
    while (qf < qb)
        for (int x=*qf++, y=0; y<n; ++y)
            if (!vy[y] && lx[x] + ly[y] == adj[x][y])
            {
                vy[y] = true;
                if (my[y] == -1)
                {
                    augment(x, y);
                    return true;
                }

                int z = my[y];
                *qb++ = z; p[z] = x; vx[z] = true; relax(z);
            }
    return false;
}

// 延展交錯樹：使用新添的等邊
bool branch2()
{
    for (int y=0; y<n; ++y)
    {
        if (!vy[y] && dy[y] == 0)
        {
            vy[y] = true;
            if (my[y] == -1)
            {
                augment(pdy[y], y);
                return true;
            }

            int z = my[y];
            *qb++ = z; p[z] = pdy[y]; vx[z] = true; relax(z);
        }
    }
    return false;
}

int Hungarian()
{
    // 初始化vertex labeling
//  memset(lx, 0, sizeof(lx));  // 任意值皆可
    memset(ly, 0, sizeof(ly));
    for (int x=0; x<n; ++x)
        for (int y=0; y<n; ++y)
            lx[x] = max(lx[x], adj[x][y]);

    // X側每一個點，分別建立「等邊」交錯樹。
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    for (int x=0; x<n; ++x)
    {
        memset(vx, false, sizeof(vx));
        memset(vy, false, sizeof(vy));
        memset(dy, 0x7f, sizeof(dy));
        qf = qb = q;
        *qb++ = x; p[x] = -1; vx[x] = true; relax(x);
        while (true)
        {
            if (branch1()) break;
            reweight();
            if (branch2()) break;
        }
    }

    // 計算最大權完美匹配的權重
    int weight = 0;
    for (int x=0; x<n; ++x)
        weight += adj[x][mx[x]];
    return weight;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", adj[i]+j);
        printf("%d\n", Hungarian());
    }
    return 0;
}
