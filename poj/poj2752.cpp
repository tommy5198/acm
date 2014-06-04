// kmp
#include<cstdio>
#include<cstring>
const int Max = 400005;

char str[Max];
int len, next[Max], ans[Max];



void get_next(){
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len){
        if(j == -1 || str[i] == str[j]){
            i ++; j ++;
            next[i] = j;
        }
        else j = next[j];
    }
}



int main(){
    while(scanf("%s", str) != EOF){
        len = strlen(str);
        get_next();
        ans[0] = len;
        int n = 0, i = len;
        while(next[i] > 0){
            ans[++n] = next[i];
            i = next[i];
        }
        for(i = n; i >= 0; i --)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
