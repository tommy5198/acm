#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    int T;
    char str[11], pre[11], ft[11];
    scanf("%d", &T);
    getchar();
    while(T--) {
        gets(str);
        int len = strlen(str);
        sort(str, str+strlen(str));
        puts(str);
        strcpy(pre, str);
        strcpy(ft, str);
        while(next_permutation(str, str+len)) {
            if(!strcmp(ft, str)) break;
            if(strcmp(pre, str)) puts(str);
            strcpy(pre, str);
        }
        puts("");
    }
    return 0;
}
