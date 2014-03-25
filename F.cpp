#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        printf("Case %d:\n", t);
        int n, k;
        int rx[100], ry[100], r[100];
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; i++)
            scanf("%d%d%d", rx+i, ry+i, r+i);
        for(int i=0; i<k; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            for(int i=0; i<n; i++)
                if(r[i]*r[i] >= (x-rx[i])*(x-rx[i])+(y-ry[i])*(y-ry[i])){
                    puts("Yes");
                    break;
                }else if(i == n-1)
                    puts("No");
        }
    }
    return 0;
}
