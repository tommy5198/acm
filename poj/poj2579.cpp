#include<cstdio>

int n, m;
int num[9][9];
int ans[8][8];

bool init(){
    char str[11];
    scanf("%s", str);
    if(str[3] == 'O')
        return false;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", num[i]+j);
    scanf("%s", str);
}

void sol(){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++)
            printf("%d", (num[i][j]+num[i][j+1]+num[i+1][j]+num[i+1][j+1])/4);
        puts("");
    }
}
int main(){
    while(init())
        sol();
    return 0;
}
