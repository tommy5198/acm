#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    puts("Lumberjacks:");
    while(n--){
        int order = 0, pre, a;
        scanf("%d%d", &pre, &a);
        if(a > pre) order = 1;
        else order = 2;
        pre = a;
        for(int i=2; i<10; i++){
            scanf("%d", &a);
            if(order < 0) continue;
            if(a > pre && order == 2)
                order = -1;
            else if(a < pre && order == 1)
                order = -1;
            pre = a;
        }
        if(order < 0)
            puts("Unordered");
        else
            puts("Ordered");
    }
    return 0;
}
