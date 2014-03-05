#include<cstdio>
#include<cstring>
#define sc scanf

int n;
char m[200][201];
int d[6][2] = {{-1,-1},{0,-1},{-1,0},{1,1},{1,0},{0,1}};

bool dfs(int y, int x){
    if(y == n - 1)
        return true;
    m[y][x] = 0;
    for(int i=0; i<6; i++)
        if(m[y+d[i][0]][x+d[i][1]] == 'b' && dfs(y+d[i][0], x+d[i][1]))
            return true;


    return false;
}
int main(){
    int c = 1;
    while(sc("%d", &n), n!=0){
        int i;
        memset(m, 0, sizeof(m));
        for(i=0;i<n;i++)
            sc("%s",m[i]);
        for(i=0; i<n; i++)
            if(m[0][i] == 'b'&& dfs(0,i)){
                printf("%d B\n", c++);
                break;
            }
        if(i == n)
            printf("%d W\n", c++);
    }
    return 0;
}
