#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct{
    int d;
    int p;
    int n;
}j;

bool cmp(j x,j y){
    if(x.d*y.p < x.p*y.d)
        return true;
    else if(x.p*y.d==x.d*y.p && x.n < y.n)
        return true;
    else
        return false;
}

int main(){
    int m;
    int b=0;
    while(scanf("%d", &m) != EOF){
        int bb=m;
        while(m--){
            if(bb!=m&&b)
                puts("");
            b=1;
            int n;

            scanf("%d", &n);
            j c[n];
            for(int i=0;i<n;i++){
                scanf("%d%d", &c[i].d, &c[i].p);
                c[i].n=i+1;
            }
            sort(c,c+n,cmp);
            for(int i=0;i<n;i++){
                printf("%d", c[i].n);
                if(i!=n-1)
                    printf(" ");
            }
            puts("");
        }
    }

    return 0;
}
