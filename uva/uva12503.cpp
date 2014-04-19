#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, final = 0;
        int cmd[101];
        scanf("%d", &n);
        char str[6];
        for(int i=1; i<=n; i++){
            scanf("%s", str);
            if(str[0] == 'L')
                cmd[i] = -1;
            else if(str[0] == 'R')
                cmd[i] = 1;
            else{
                int t;
                scanf("%s%d", str, &t);
                cmd[i] = cmd[t];
            }
            final += cmd[i];
        }
        printf("%d\n", final);
    }
    return 0;
}
