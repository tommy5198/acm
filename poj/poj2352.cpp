// RQ, bidxTree
#include<cstdio>
int x[15001], y[15001];
int s[32002];
int lv[15001];
int mx, my;

int lowbit(int in) {
    return in&(-in);
}

void add(int a, int d) {
    for(int i=a; i<=mx; i+=lowbit(i))
        s[i] += d;
}

int getsum(int a) {
    int ret = 0;
    for(int i=a; i; i-=lowbit(i))
        ret += s[i];
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", x+i, y+i);
        x[i]++;
        mx = mx<x[i] ? x[i] : mx;
    }
    for(int i=0; i<n; i++) {
        lv[getsum(x[i])]++;
        add(x[i], 1);
    }
    for(int i=0; i<n; i++)
        printf("%d\n", lv[i]);
    return 0;
}
