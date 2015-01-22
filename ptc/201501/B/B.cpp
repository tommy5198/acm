#include<cstdio>
#include<cstring>

int nx, ny;             // X���I�ƥءBY���I�ƥ�
int mx[1000], my[1000];   // X�U�I���t���H�BY�U�I���t���H
bool vy[1000];           // ����Graph Traversal���X�L���I
bool adj[1000][1000];     // ��²�L��adjacency matrix

// �HDFS�إߤ@�ʥ����
bool DFS(int x)
{
    for (int y=0; y<ny; ++y)
        if (adj[x][y] && !vy[y])
        {
            vy[y] = true;

            // ����X�R���|
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
    // �������I��l�Ƭ����ǰt�I�C
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));

    // �̧ǧ�X�����C�@���I�@���X�R���|�����I�A
    // �ù��մM���X�R���|�C
    int c = 0;
    for (int x=0; x<nx; ++x)
//      if (mx[x] == -1)    // x�����ǰt�I�A�o��i��²�C
        {
            // �}�lGraph Traversal
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
