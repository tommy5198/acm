//back track
#include<cstdio>

int n;
int sudoku[9][9];

bool checkbox(int x, int y, int v){
    int a = x/n, b = y/n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(sudoku[a*n+i][b*n+j] == v)
                return false;
    //printf("b ");
    return true;
}
bool checkrow(int x, int y, int v){
    for(int i=0; i<n*n; i++)
        if(sudoku[x][i] == v)
            return false;
    //printf("r ");
    return true;
}
bool checkcol(int x, int y, int v){
    for(int i=0; i<n*n; i++)
        if(sudoku[i][y] == v)
            return false;
    //printf("c \n");
    return true;
}
bool sol(int x, int y){
    if(x == n*n) return true;
    //printf("%d-%d\n", x, y);
    if(sudoku[x][y] == 0)
        for(int i=1; i<=n*n; i++){
            //printf("%d\n", i);
            if(checkbox(x, y, i) && checkrow(x, y, i) && checkcol(x, y, i)){
               //printf("==%d\n", i);
                sudoku[x][y] = i;
                if(y == n*n-1 && sol(x+1, 0))
                    return true;
                else if(sol(x, y+1))
                    return true;
                sudoku[x][y] = 0;
            }
        }
    else{
        if(y == n*n-1 && sol(x+1, 0))
            return true;
        else if(sol(x, y+1))
            return true;
    }
    return false;
}
int main(){
    bool first = true;
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) != EOF){
        for(int i=0; i<n*n; i++)
            for(int j=0; j<n*n; j++)
                scanf("%d", &sudoku[i][j]);
        if(!first) printf("\n");
        else first = false;
        if(sol(0, 0))
            for(int i=0; i<n*n; i++){
                for(int j=0; j<n*n; j++){
                    if(j) printf(" ");
                    printf("%d", sudoku[i][j]);
                }
                printf("\n");
            }
        else
            printf("NO SOLUTION\n");

    }
    return 0;
}
