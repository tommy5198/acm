#include<cstdio>

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){

        int bit, mask = (1<<n )- 1;
        int a = 0, b = 0, oneA = 0, oneB = 0, xo;
        int ansA = 0, ansB = 0, cnt = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &bit);
            a |= bit<<i;
            oneA += bit;
        }
        for(int i=0; i<m; i++){
            scanf("%d", &bit);
            b |= (i&1) ? ((1 << bit)-1)<<cnt : 0;
            oneB += (i&1) ? bit : 0;
            cnt += bit;
        }
        if(oneA != oneB)
            b ^= mask;
        xo = a ^ b;
        for(int i=0; i<n; i++)
            if(xo & (1<<i))
                for(int j=i+1; j<n; j++)
                    if((xo & (1<<j) ) && ((a>>i)&1) !=  ((a>>j)&1) ) {
                        ansA += j - i;
                        xo ^= (1<<j);
                        break;
                    }
        if(oneA<<1 == n){
            b ^= mask;
        xo = a ^ b;
        for(int i=0; i<n; i++)
            if(xo & (1<<i))
                for(int j=i+1; j<n; j++)
                    if((xo & (1<<j) ) && ((a>>i)&1) !=  ((a>>j)&1)  ) {
                        ansB += j - i;
                        xo &= mask-(1<<i)-(1<<j);
                    }
            ansA = ansA > ansB ? ansB : ansA;
        }
        printf("%d\n", ansA);
    }
    return 0;
}
