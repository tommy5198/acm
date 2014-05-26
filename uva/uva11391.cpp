// bit mask
#include<cstdio>
#include<cstring>

int R, C,r, c, n, ca, ans, bn;
int mi[5][5][1<<16];

void init(){
    scanf("%d%d%d", &r, &c, &n);
    ans = 0;
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        ans |= 1<<c*a+b;
    }
}

void dfs(int bsum, int bcnt, int bit){
    if(!bsum){
        if(!mi[R][C][bit]) return ;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                int tmp;
                if(j<c-2){
                    tmp = 1<<i*c+j | 1<<i*c+j+1 | 1<<i*c+j+2;
                    if( (bit&tmp) == 1<<i*c+j)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                    tmp = 1<<i*c+c-j-1 | 1<<i*c+c-j-2 | 1<<i*c+c-j-3;
                    if( (bit&tmp) == 1<<i*c+c-j-1)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                }
                if(i<r-2){
                    tmp = 1<<i*c+j | 1<<(i+1)*c+j | 1<<(i+2)*c+j;
                    if( (bit&tmp) == 1<<i*c+j)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                    tmp = 1<<(r-i-1)*c+j | 1<<(r-i-2)*c+j | 1<<(r-i-3)*c+j;
                    if( (bit&tmp) == 1<<(r-i-1)*c+j)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                }
                if(i<r-2 && j<c-2){
                    tmp = 1<<i*c+j | 1<<(i+1)*c+j+1 | 1<<(i+2)*c+j+2;
                    if( (bit&tmp) == 1<<i*c+j)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                    tmp = 1<<i*c+c-j-1 | 1<<(i+1)*c+c-j-2 | 1<<(i+2)*c+c-j-3;
                    if( (bit&tmp) == 1<<i*c+c-j-1)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                    tmp = 1<<(r-i-1)*c+j | 1<<(r-i-2)*c+j+1 | 1<<(r-i-3)*c+j+2;
                    if( (bit&tmp) == 1<<(r-i-1)*c+j)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                    tmp = 1<<(r-i-1)*c+c-j-1 | 1<<(r-i-2)*c+c-j-2 | 1<<(r-i-3)*c+c-j-3;
                    if( (bit&tmp) == 1<<(r-i-1)*c+c-j-1)
                        mi[R][C][bit^tmp] += mi[R][C][bit];
                }
            }
        return ;
    }
    if(bcnt == r*c) return ;
    dfs(bsum-1, bcnt+1, bit|1<<bcnt);
    dfs(bsum, bcnt+1, bit);
}

void sol(){
    //for(bn=1; bn<n; bn++)
      //  dfs(bn, 0, 0);
    printf("Case %d: %d\n", ca++, mi[r][c][ans]);
}

void pre(){
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
        {
            R = r = i;
            C = c = j;
            for(int k=0; k<r*c; k++) mi[r][c][1<<k] = 1;
            for(bn=1; bn<r*c; bn++)
                dfs(bn, 0, 0);
        }
}

int main(){
    int T;
    scanf("%d", &T);
    ca = 1;
    pre();
    while(T--){
        init();
        sol();
    }
    return 0;
}
