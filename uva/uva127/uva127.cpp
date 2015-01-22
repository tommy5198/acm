#include<cstdio>

int stk[52][52];
int top[53], Top, piles;

int main(){
    char card[3];
    Top = -1, piles = 52;
    for(int i=0; i<52; i++) top[i] = -1;
    while(scanf("%s", card), card[0] != '#') {
        ++Top;
        stk[Top][++top[Top]] = card[0]*1000 + card[1];
        for(int i=1; i<=Top; i++) {
            if(~top[i])
            for(int j=0; j < i; j++)
                if(~top[j]) {
                    int prev = stk[j][top[j]], next = stk[i][top[i]];
                    if(prev%1000 == next%1000 || prev/1000 == next/1000) {
                        stk[j][++top[j]] = stk[i][top[i]--];
                        i = j;
                        if(top[i] == -1) piles--;
                        break;
                    }
                }
        }

        if(Top == 52 - 1) {
            Top = -1;
            if(piles == 1)
                puts("1 pile remaining: 52");
            else {
                printf("%d piles remaining:", piles);
                for(int i=0; i<52; i++) {
                    if(~top[i]) printf(" %d", top[i]+1);
                    top[i] = -1;
                }
                puts("");
            }
            piles = 52;
        }
    }
    return 0;
}
