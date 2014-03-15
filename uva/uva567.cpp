//Flyod_Warshall
#include<cstdio>
#include<cstring>
int w[21][21];
int d[21][21];

void Flyod_Warshall(){
    for(int i=1; i<=20; i++)
        for(int j=1; j<=20; j++)
            d[i][j] = w[i][j];
    for(int i=1; i<=20; i++)
        d[i][i] = 0;
    for(int k=1; k<=20; k++)
        for(int i=1; i<=20; i++)
            for(int j=1; j<=20; j++)
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
}

int main(){
    int a, b, n, T = 1;
    while(scanf("%d", &n) != EOF){
        for(int i=1; i<=20; i++)
            for(int j=1; j<=20; j++)
                w[i][j] = 10;
        for(int i=1; i<20; i++){
            while(n--){
                scanf("%d", &a);
                w[i][a] = w[a][i] = 1;
            }
            scanf("%d", &n);
        }
        Flyod_Warshall();

        printf("Test Set #%d\n", T++);
        while(n--){
            scanf("%d%d", &a, &b);
            printf("%2d to %2d: %d\n", a, b, d[a][b]);
        }
        puts("");
    }
    return 0;
}
