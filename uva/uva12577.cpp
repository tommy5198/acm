#include<cstdio>

int main(){
    char str[6];
    int T = 1;
    while(scanf("%s", str), str[0] != '*')
        if(str[0] == 'H')
            printf("Case %d: Hajj-e-Akbar\n", T++);
        else
            printf("Case %d: Hajj-e-Asghar\n", T++);
    return 0;
}
