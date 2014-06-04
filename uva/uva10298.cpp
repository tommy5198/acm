// prefix
#include<cstdio>

char str[1000005];
int p[1000005];
int len;

void prefix(){
    len = 1;
    for(int i=2, j=0; str[i]; i++, len++){
        while(j > 0 && str[j+1] != str[i])
            j = p[j];
        if(str[j+1] == str[i])
            j++;
        p[i] = j;
    }
}

void sol(){
}

int main(){
    while(scanf("%s", str+1), str[1] != '.'){
        prefix();
        sol();
        printf("%d\n", len/(len-p[len]));
    }
    return 0;
}
