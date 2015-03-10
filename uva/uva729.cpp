#include<cstdio>

char bit[20];
int n, m;
void btk(int zcnt, int ocnt) 
{
    if(zcnt + ocnt == 0) {
        puts(bit);          
        return ;
    }
    if(zcnt) {
        bit[n - zcnt - ocnt] = '0';
        btk(zcnt - 1, ocnt);
    }
    if(ocnt) {
        bit[n - zcnt - ocnt] = '1';
        btk(zcnt, ocnt - 1);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        bit[n] = 0;
        btk(n - m, m);
        if(T) puts("");
    }
    return 0;
}
