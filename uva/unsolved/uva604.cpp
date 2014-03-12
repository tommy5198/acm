#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct Word{
    char w[5];
    bool operator<(const Word &t)const{
        for(int i=0; i<4; i++)
            if(w[i] != t.w[i])
                return w[i]<t.w[i];
        return true;
    }
}Tmp;

int lr;
char b[2][6][6];
int dir[8][2] = { {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {-1, 1}, {1, -1} };
vector<Word> W[2];
bool used[6][6];
bool VOW(char c){
    char vowel[7] = "AEIOUY";
    for(int i=0; i<6; i++)
        if(c == vowel[i])
            return true;
   return false;
}
void dfs(int x, int y, int d, bool vow){
    Tmp.w[d] = b[lr][x][y];
    if(d == 3){
        if(vow)
            W[lr].push_back(Tmp);
        return ;
    }

    for(int i=0; i<8; i++){
        int X = x+dir[i][0], Y = y+dir[i][1];
        char tmp = b[lr][X][Y];
        if(!used[X][Y] && tmp >= 'A'){
            used[X][Y] = true;
            //if(VOW('Z'))
            //printf("%c\n", tmp);
            dfs(x+dir[i][0], y+dir[i][1], d+1, vow || VOW(tmp));
            used[X][Y] = false;
        }
    }
}
void check(){
    //freopen("t.out", "w", stdout);
    int pre = 0;
    sort(W[0].begin(), W[0].end());
    sort(W[1].begin(), W[1].end());
    for(int i=0, j = 0; i<W[0].size(); i++){
        //if(W[0][i].w[0] == 'A') printf("%s\n", W[0][i].w);
        for(; j<W[1].size(); j++)
            if(!strcmp(W[0][i].w, W[1][j].w) ){
                printf("%s\n", W[0][i].w);
                j++;
                pre = j;
                break;
            }
        if(j == W[1].size())
            j = pre;
    }
    if(!pre) puts("There are no common words for this pair of boggle boards.");
    else puts("");
    //if(VOW(b[0][0][0]))
    //printf("%d %d\n", W[0].size(), W[1].size());
}
void build(){
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++){
            char L = b[0][i][j], R = b[1][i][j];
            //printf("%d %d\n", W[0].size(), W[1].size());
            lr = 0;
            used[i][j] = true;
            dfs(i, j, 0, VOW(L));
            lr = 1;
            dfs(i, j, 0, VOW(R));
            used[i][j] = false;
        }
}

bool init(){
    W[0].clear();
    W[1].clear();
    for(int i=0; i<6; i++)
    for(int j=0; j<6; j++){
        used[i][j] = false;
        b[0][i][j] = b[1][i][j] = 0;
    }
    printf("II\n");
    for(int i=1; i<=4; i++){
        for(int x=1; x<=4; x++){
            b[0][i][x] = getchar();
            if(b[0][i][x] == '#'){
                printf("re\n");
                return false;
            }
            getchar();
        }
        getchar(); getchar(); getchar();
        for(int x=1; x<=4; x++){
            b[1][i][x] = getchar();
            getchar();
        }
    }
    return true;
}
int main(){
    freopen("t.in", "r", stdin);
    bool k = false;
    while(init()){
        if(k) puts("");
        else k = true;
        printf("I\n");
        build();
        printf("b\n");
        check();
        printf("c\n");
        getchar();
    }
    printf("rere\n");

    return 0;
}
