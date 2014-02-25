#include<cstdio>


int main(){
    int T, N, num[75][75];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &num[i][j]);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int y=0; y<N; y++){
                    for(int x=0; x<=y; x++){

                    }
                }
            }
        }
    }
}
