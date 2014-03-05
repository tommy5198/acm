//back tracking
#include<cstdio>

int sum;
int num[8][8];
bool chess[8][8];

void queen(int tsum, int d){
    if(d == 8){
        sum = sum > tsum ? sum : tsum;
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
            queen(tsum+num[d][i], d+1);
            chess[d][i] = false;
        }
    }
}
int main(){
    
    int k;
    scanf("%d", &k);
    while(k--){
        sum = -1;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++){
                scanf("%d", &num[i][j]);
                chess[i][j] = false;
            }
        queen(0, 0);
        printf("%5d\n", sum);
    }
    return 0;
}
