// 2D binary index tree
#include<cstdio>
#include<cstring>

int table[200][200];

int lowbit(int x){
    return x&(-x);
}

void add(int x, int y, int delta){
    for(int i=x; i<200; i+=lowbit(i))
        for(int j=y; j<200; j+=lowbit(j))
            table[i][j] += delta;
}

int sum(int x, int y){
    int sm = 0;
    for(int i=x; i; i-=lowbit(i))
        for(int j=y; j; j-=lowbit(j))
            sm += table[i][j];
    return sm;
}

bool query(int x1, int y1, int x2, int y2){
    return !(sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1));
}

void sol(){
    int n, ans = 0;
    memset(table, 0, sizeof(table));
    scanf("%d", &n);
    while(n--){
        int a[4];
        for(int i=0; i<4; i++){
            scanf("%d", a+i);
            a[i] += 100;
        }
        if(query(a[0], a[1], a[2]-1, a[3]-1))
        for(int x=a[0]; x < a[2]; x++)
        for(int y=a[1]; y < a[3]; y++){
            ans++;
            add(x, y, 1);
        }
    }
    printf("%d\n", ans);

}

int main(){
    int ca;
    scanf("%d", &ca);
    for(int i=1; i<=ca; i++){
        printf("Case %d: ", i);
        sol();
    }
    return 0;
}
