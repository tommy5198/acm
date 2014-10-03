#include<cstdio>
#include<cstring>

int main(){
    int T;
    char sa[51], sb[51];
    scanf("%d", &T);
    while(T--){
        int a, b;
        scanf("%s%s", sa, sb);
        for(a = 0, b = 0; sa[a]&&sb[b]&&sa[a]==sb[b]; a++, b++);
        if(!sb[b])
            printf("%s*\n", sa+a);
        else if(!sa[a]){
            if(strlen(sb)-b < b+1){
                while(sb[b++])
                    printf("<");
                puts("*");
            }else
                printf("*%s*\n", sa);
        }else if(strlen(sb)-b+strlen(sa)-a < strlen(sa)+1){
            while(sb[b++])
                printf("<");
            printf("%s*\n", sa+a);
        }else
            printf("*%s*\n", sa);
    }
    return 0;
}
