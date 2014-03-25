#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char str[11];
        scanf("%s", str);
        if(str[3])
            puts("3");
        else if(str[1] == 'w' && str[2] == 'o' || str[0] == 't' && str[1] == 'w' || str[0] == 't' && str[2] == 'o')
            puts("2");
        else
            puts("1");
    }
    return 0;
}
