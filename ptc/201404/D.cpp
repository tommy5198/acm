#include<cstdio>


int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i)
    while(T--){
        int n, one = 0;
        char A[201];
        int F[201];
        scanf("%d", &n);
        getchar();
        for(int i=1; i<=n; i++)
            A[i] = getchar();
        getchar();
        for(int i=0; i<n; i++)
            if(getchar() == '1')
                one++;
        for(int i=1; i<=n; i++){
            int tmp = one-i>i ? one-i : i;
            if(one==i || one%2 )
        }
        one = 0;
        for(int i=1; i<=n; i++)
            if(A[i] == '1' && F[i])
                one++;
        printf("%d\n", one%2);
    }
    return 0;
}
