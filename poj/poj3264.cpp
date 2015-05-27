// RQ, static segTree
#include<cstdio>
#define INF 100000000

int mx[1>>16+1], mi[1>>16+1];
int h[50000];

void build(int idx, int L, int R) {
    
    if(L == R) {
        mx[idx] = h[L];
        mi[idx] = h[L];
        return;
    }
    int mid = (L+R)>>1;
    build(idx*2, L, mid);
    build(idx*2+1, mid+1, R);
    mx[idx] = mx[idx*2]<mx[idx*2+1] ? mx[idx*2+1] : mx[idx*2];
    mi[idx] = mi[idx*2]<mi[idx*2+1] ? mi[idx*2] : mi[idx*2+1];
}

int query(int idx, int L, int R, int A, int B, bool flag) {
    if(L>B || R<A)
        return flag ? -INF : INF;
    if(A<=L && R<=B)
        return flag ? mx[idx] : mi[idx];
    int mid = (L+R)>>1;
    int Lv = query(idx*2, L, mid, A, B, flag);
    int Rv = query(idx*2+1, mid+1, R, A, B, flag);
    if(Lv < Rv)
        return flag ? Rv : Lv;
    return flag ? Lv : Rv;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=0; i<n; i++) 
        scanf("%d", h+i);
    build(1, 0, n-1);
    for(int i=0; i<q; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        printf("%d\n", query(1, 0, n-1, A-1, B-1, true) - query(1, 0, n-1, A-1, B-1, false));
        //printf("%d %d\n", query(1, 0, n-1, A-1, B-1, true) , query(1, 0, n-1, A-1, B-1, false));
    }
    return 0;
}
