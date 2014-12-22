// easy stack
#include<cstdio>
int stk[1000];
int num[1000];

int main(){
    int N, ft = 0;
    while(scanf("%d", &N), N){

        while(scanf("%d", num), num[0]){
            int top = -1, n = N;
            for(int i=1; i<N; i++)
                scanf("%d", num+i);
            for(int i=N-1; ~i; i--) {
                stk[++top] = num[i];
                while(~top && stk[top] == n)
                    n--, top--;
            }
            puts(~top ? "No" : "Yes" );
        }
        puts("");
    }
    return 0;
}
