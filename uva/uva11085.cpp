//8 queen back tracking
#include<cstdio>

int queen[8];
bool chess[8][8];
int ans;
void check(int d){
    if(d == 8){
        int mv = 8;
        for(int i=0; i<8; i++)
            if(chess[i][queen[i]])
                mv--;
        ans = ans>mv ? mv : ans;
        return ;
    }
    for(int i=0; i<8; i++){
        int j, x;
        for(j=d-1, x=1; j>=0; j--, x++){
            if(chess[j][i])
                break;
            if(i+x < 8 && chess[j][i+x])
                break;
            if(i-x >= 0 && chess[j][i-x])
                break;
        }
        if(j == -1){
            chess[d][i] = true;
            check(d+1);
            chess[d][i] = false;
        }
    }
}
void init(){
    for(int i=0; i<8; i++){
        queen[i]--;
        for(int j=0; j<8; j++)
            chess[i][j] = false;
    }
    ans = 9;
}
int main(){
    int T = 1;
    while(scanf("%d", &queen[0]) != EOF){
        for(int i=1; i<8; i++)
            scanf("%d", &queen[i]);
        init();
        check(0);
        printf("Case %d: %d\n", T++, ans);
    }
    return 0;
}
