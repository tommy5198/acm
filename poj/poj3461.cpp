// kmp
#include<cstdio>

char word[10005];
char text[1000005];
int p[10005];

void init(){
    scanf("%s%s", word+1, text);
    
    // compute prefix
    for(int i=2, j=0; word[i]; i++){
        while(j > 0 && word[j+1] != word[i])
            j = p[j];
        if(word[j+1] == word[i])
            j++;
        p[i] = j;
    }
}

void kmp(){
    
    int cnt = 0;

    for(int i=0, j=0; text[i]; i++){
        while(j > 0 && word[j+1] != text[i])
            j = p[j];
        if(word[j+1] == text[i])
            j++;
        if(!word[j+1]){
            cnt++;
            j = p[j];
        }
    }
    printf("%d\n", cnt);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        kmp();
    }
    return 0;
}
