#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct P{
    int x, y, z, m;
    bool operator==(const P &t)const{
        return x==t.x&&y==t.y&&z==t.z;
    }
};

int L, R, C;
char m[32][32][32];
int dir[6][3] = {{0, 0, 1}, {0, 1, 0}, {0, -1, 0}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}};

P now, tmp;

int main(){

    while(scanf("%d%d%d", &L, &R, &C) != EOF){
        if(!L)
            break;
        P S, E;

        memset(m, 0, sizeof(m));
        for(int i=1; i<=L; i++)
            for(int j=1; j<=R; j++)
                for(int k=1; k<=C; k++){
                    scanf("%c", &m[i][j][k]);
                    while(m[i][j][k] == '\n')
                        scanf("%c", &m[i][j][k]);
                    if(m[i][j][k] == 'S')
                        S.z = i, S.y = j, S.x = k, S.m=0;
                    else if(m[i][j][k] == 'E')
                        E.z = i, E.y = j, E.x = k, E.m=0;
                }

        queue<P> Q;
        Q.push(S);
        while(!Q.empty() && !E.m){
            now = Q.front();
            Q.pop();
            for(int i=0; i<6; i++){
                tmp.x = now.x+dir[i][2];
                tmp.y = now.y+dir[i][1];
                tmp.z = now.z+dir[i][0];
                tmp.m = now.m+1;

                if(m[tmp.z][tmp.y][tmp.x] == '.'){
                    Q.push(tmp);
                    m[tmp.z][tmp.y][tmp.x] = '#';
                }else if(m[tmp.z][tmp.y][tmp.x] == 'E'){

                    E.m = tmp.m;
                    break;
                }
            }
        }
        if(E.m)
            printf("Escaped in %d minute(s).\n", E.m);
        else
            printf("Trapped!\n");
    }
    return 0;
}
