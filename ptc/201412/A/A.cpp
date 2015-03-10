#include<cstdio>

int two[100];
int mat[10000][10000];
int f[100];
int main(){

    int T;
    scanf("%d", &T);
    two[0] = 1; f[0] = 1;
    mat[0][0][0] = 0;
    mat[0][1][0] = 1;
    mat[0][0][1] = 3;
    mat[0][1][1] = 2;

    for(int i=1; i<13; i++){
        two[i] = 2*two[i-1];
        f[i] = 4*f[i-1];
    }
    for(int i=2; i<=T; i++) 
        for(int j=0; j<two[i-1]; j++)
            for(int k=0; k<two[i-1]; k++) {
                mat[!(i&1)][j][k] = mat[i&1][k][j];
                mat[!(i&1)][j+two[i-1]][k] = mat[i&1][j][k] + f[i-1];
                mat[!(i&1)][j+two[i-1]][k+two[i-1]] = mat[!(i&1)][j+two[i-1]][k] + f[i-1];
                mat[!(i&1)][j][k+two[i-1]] = mat[i&1][two[i-1]-k-1][two[i-1]-j-1] + f[i-1]*3;
            }
    

    for(int i=two[T]-1; ~i; --i){
        for(int j=0; j<two[T]; j++)
            printf("%d ", mat[!(T&1)][i][j]);
        puts("");
    }


/*


    for(int i=3; i<=T; i++) {
        for(int j=0; j<two[i-2]; j++)
            for(int k=0; k<two[i-2]; k++){
                mat[j][two[i-2] + k] = mat[j][k];
                mat[two[i-1]-k-1][j] = mat[j][k];
                mat[two[i-2]+k][two[i-1]-j-1] = mat[j][k];
            }
    }
    for(int i=0; i<two[T-1]; i++){
        for(int j=0; j<two[T-1]; j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
    for(int i=two[T-1]-1; ~i; i--)
        for(int j=0; j<two[T-1]-1; j++) 
            if(mat[i][j]) {
                d[x][y] = num++;
                d[x]
            }
    */
    return 0;
}
