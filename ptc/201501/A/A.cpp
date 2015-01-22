#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int X = 1000;   // X���I�ƥءA����Y���I�ƥ�
const int Y = 1000;   // Y���I�ƥ�
int adj[X][Y];      // ��²�L��adjacency matrix
int lx[X], ly[Y];   // vertex labeling
int mx[X], my[Y];   // X�U�I���t���H�BY�U�I���t���H
int q[X], *qf, *qb; // BFS queue
int p[X];           // BFS parent�A����𤧰��I�A���V�W�@�Ӱ��I
bool vx[X], vy[Y];  // �����O�_�b�����W
int dy[Y], pdy[Y];  // DP���
 int n;
// relaxation
void relax(int x)
{
    for (int y=0; y<n; ++y)
        if (adj[x][y] != 1e9)
            if (lx[x] + ly[y] - adj[x][y] < dy[y])
            {
                dy[y] = lx[x] + ly[y] - adj[x][y];
                pdy[y] = x; // �����n�O�q���Ӿ𸭳s�X�h��
            }
}

// �վ�����W��label�B�վ�DP���
void reweight()
{
    int d = 1e9;
    for (int y=0; y<n; ++y) if (!vy[y]) d = min(d, dy[y]);
    for (int x=0; x<n; ++x) if ( vx[x]) lx[x] -= d;
    for (int y=0; y<n; ++y) if ( vy[y]) ly[y] += d;
    for (int y=0; y<n; ++y) if (!vy[y]) dy[y] -= d;
}

// �X�R���|
void augment(int x, int y)
{
    for (int ty; x != -1; x = p[x], y = ty)
    {
        ty = mx[x]; my[y] = x; mx[x] = y;
    }
}

// ���i�����G�ϥάJ��������
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

// ���i�����G�ϥηs�K������
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
    // ��l��vertex labeling
//  memset(lx, 0, sizeof(lx));  // ���N�Ȭҥi
    memset(ly, 0, sizeof(ly));
    for (int x=0; x<n; ++x)
        for (int y=0; y<n; ++y)
            lx[x] = max(lx[x], adj[x][y]);

    // X���C�@���I�A���O�إߡu����v�����C
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

    // �p��̤j�v�����ǰt���v��
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
