#include<cstdio>

struct edge{
    int a, b, dis;
    bool operator<(const edge &t)const{
        return dis<t.dis;
    }
};

edge e[]
int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d%d", x+i, y+i);
            for(int j=0; j<i; j++)
                e[cnt++] = (edge){i, j, abs(x[i]-x[j]) + abs(y[i]-y[j])};
        }
        sort(e, e+cnt);
        
        for(int i=0, j = 0; i<cnt && j!=n-1; i++) {
            int a = findr(e[i].a), b = findr(e[i].b);
            if(a != b) {
                ans += e[i].dis;
                uni(a, b);
                j++;
            }
        }
        printf("%d\n", cnt);

    }
    return 0;
}
