#include<cstdio>
#include<cstring>
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char str[1000];
        scanf("%s", str);
        int L = strlen(str);
        if(!strcmp(str, "1") || !strcmp(str, "4") || !strcmp(str, "78"))
            puts("+");
        else if(str[L-1] == '5' && str[L-2] == '3')
            puts("-");
        else if(str[0] == '9' && str[L-1] == '4')
            puts("*");
        else
            puts("?");
    }
    return 0;
}
