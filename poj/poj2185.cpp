// 2D prefix
#include<cstdio>
#include<cstring>

int a, r, c;
int p[10001];
char cow[10001][76];
char rcow[76][10001];

void init(){
    scanf("%d%d", &r, &c);
    for(int i=1; i<=r; i++){
        getchar();
        for(int j=0; j<c; j++)
            cow[i][j] = getchar();
    }
}


template <class T>
int prefix(T str, int len){
    
    for(int i=2, j=0; i<=len; i++){
        while(j > 0 && strcmp(str[j+1], str[i]))
            j = p[j];
        if(!strcmp(str[j+1], str[i]))
            j++;
        p[i] = j;
    }
    return len - p[len];
}

void sol(){
    a = prefix<char[][76]>(cow, r);

    for(int i=1; i<=c; i++)
        for(int j=1; j<=a; j++)
            rcow[i][j-1] = cow[j][i-1];
    
    printf("%d\n", a * prefix<char[][10001]>(rcow, c));
}   

int main(){
    init();
    sol();
    return 0;
}
