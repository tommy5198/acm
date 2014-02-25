//need rewrite DFS
#include<cstdio>
#include<cstring>
int grp, n, ff, em;
char a[55][55];
int d[4][2]={ {1,0}, {-1,0}, {0,1}, {0,-1} };
bool Fight;
void DFS(int x, int y){


}
int main(){
    int S = 0;
    while(scanf("%d", &n), n){
        if(S == 0)
            S = 1;
        else
            printf("\n");
        int Sec = 1;
        grp = 0;
        memset(a, 0, sizeof(a));
        for(int i=1; i<=n; i++)
            scanf("%s", &a[i][1]);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)


        printf("Total %d group(s) are in fighting position.\n", grp);
    }
    return 0;
}
