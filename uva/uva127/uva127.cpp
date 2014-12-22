#include<cstdio>

int stk[52][52];
int top[53], Top;

int main(){
    char card[3], cnt = 1;
    while(scanf("%s", card), card[0] != '#') {
        stk[++top[0]][++top[cnt]] = card[0]*1000 + card[1];

        if(cnt == 52) {
            cnt = 1;

        }
    }
    return 0;
}
