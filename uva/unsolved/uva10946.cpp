//DFS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
char d[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
char a[60][60];
struct Hole{
    int size;
    char name;
    bool operator<(const Hole &t)const{
        if(size == t.size)
            return name<t.name;
        return size > t.size;
    }
};

int DFS(int x, int y){
    int sum = 1;
    char c = a[x][y];
    a[x][y] = '.';
    //printf("%c %d %d\n", a[x][y], x, y);
    for(int i=0; i<4; i++)
        if(a[x+d[i][0]][y+d[i][1]] == c){
            sum += DFS(x+d[i][0], y+d[i][1]);
        }
    return sum;
}

int main(){
    vector<Hole> ans;
    int T = 1;
    while(scanf("%d%d", &n, &m), n){
        ans.clear();
        for(int i=1; i<=n; i++)
            scanf("%s", &a[i][1]);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(a[i][j] >= 'A' && a[i][j] <= 'Z'){
                    Hole tmp;
                    tmp.name = a[i][j];
                    tmp.size = DFS(i, j);
                    ans.push_back(tmp);
                }
        sort(ans.begin(), ans.end());
        printf("Problem %d:\n", T);
        T++;
        for(int i=0; i<ans.size(); i++)
            printf("%c %d\n", ans[i].name, ans[i].size);
    }
    return 0;
}
