#include<cstdio>

int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int n;
int ans[16];
bool used[16] = {false};
void DFS(int now, int d){
    if(d == n){
        bool yes = false;
        for(int i=0; i<11; i++)
            if(now+1 == prime[i])
                yes = true;
        if(yes){
            for(int i=0; i<n; i++){
                if(i) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
        return ;
    }
    for(int i=0; i<11; i++){
        int next = prime[i] - now;
        if(!used[next] && !(next <= 0 || next > n) ){
            ans[d] = next;
            used[next] = true;
            DFS(next, d+1);
            used[next] = false;
        }
    }
}
int main(){
    int T = 1;
    ans[0] = 1;
    used[1] = true;
    while(scanf("%d", &n) != EOF){
        if(T != 1) printf("\n");
        printf("Case %d:\n", T++);
        for(int i=0; i<11; i++)
            if(prime[i]-1 <= n)
                DFS(prime[i]-1, 1);
    }
    return 0;
}
