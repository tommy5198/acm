#include<cstdio>
#include<algorithm>
#define INF 100000000
using namespace std;

int main(){
    int d[8][8][8][8];
    int t[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, -1}, {-1, -2}};
    for(int sx=0; sx<8; sx++)
        for(int sy=0; sy<8; sy++)
    for(int dx=0; dx<8; dx++)
        for(int dy=0; dy<8; dy++)
            d[sx][sy][dx][dy] = INF;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            d[i][j][i][j] = 0;
            for(int x=0; x<8; x++)
                if(i+t[x][0] >= 0 && i+t[x][0] < 8 && j+t[x][1] >=0 && j+t[x][1] <8)
                    d[i][j][i+t[x][0]][j+t[x][1]] = 1;
        }
    for(int kx=0; kx<8; kx++)
        for(int ky=0; ky<8; ky++)
    for(int sx=0; sx<8; sx++)
        for(int sy=0; sy<8; sy++)
    for(int dx=0; dx<8; dx++)
        for(int dy=0; dy<8; dy++)
            d[sx][sy][dx][dy] = min(d[sx][sy][dx][dy], d[sx][sy][kx][ky]+d[kx][ky][dx][dy]);

    char src[3], dst[3];
    while(scanf("%s %s", src, dst)!=EOF)
        printf("To get from %s to %s takes %d knight moves.\n", src, dst, d[src[0]-'a'][src[1]-'1'][dst[0]-'a'][dst[1]-'1']);

    return 0;
}
