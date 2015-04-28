#include<cstdio>

int main(){
    
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, a, pre, flag = 0, cnt = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a);
            if(i) {
                if(a != pre) {
                    if(flag) 
                        cnt++;
                    else {
                        flag = 1;
                        cnt += 2;
                    }
                }else
                    flag = 0;
            }
            pre = a;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
