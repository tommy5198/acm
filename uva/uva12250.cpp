#include<cstdio>
#include<cstring>
int main(){
    char str[15];
    int T = 1;
    while(scanf("%s", str), str[0] != '#'){
        printf("Case %d: ", T++);
        if(!strcmp(str, "HELLO"))
            puts("ENGLISH");
        else if(!strcmp(str, "HALLO"))
            puts("GERMAN");
        else if(!strcmp(str, "HOLA"))
            puts("SPANISH");
        else if(!strcmp(str, "BONJOUR"))
            puts("FRENCH");
        else if(!strcmp(str, "CIAO"))
            puts("ITALIAN");
        else if(!strcmp(str, "ZDRAVSTVUJTE"))
            puts("RUSSIAN");
        else
            puts("UNKNOWN");
    }
    return 0;
}
