#include<cstdio>
#include<cstring>

int ttl;
char p[100];
int A[100], B[10];
bool e[100][10];
bool vis[10];

bool init(){
    if((p[0]=getchar()) == -1)
        return false;
    ttl = 0;
    for(int i=0; i<10; i++)
        B[i] = -1;
    while(1){
        int num = getchar()-'0';
        getchar();
        for(int i=ttl; i<ttl+num; i++){
            A[i] = -1;
            p[i] = p[ttl];
            for(int j=0; j<10; j++)
                e[i][j] = false;
        }
        for(int i=getchar(); i!=';'; i=getchar()){
            for(int j=ttl; j<ttl+num; j++){
                e[j][i-'0'] = true;
                if(A[j]<0 && B[i-'0']<0){
                    A[j] = i-'0';
                    B[i-'0'] = j;
                }
            }
        }
        getchar();
        char tmp = getchar();
        ttl += num;
        if(tmp>0 && tmp!='\n')
            p[ttl] = tmp;
        else
            break;
    }
    return true;
}

bool dfs(int nw){
    for(int i=0; i<10; i++)
        if(!vis[i] && e[nw][i]){
            vis[i] = true;
            if(B[i]<0 || dfs(B[i])){
                A[nw] = i;
                B[i] = nw;
                return true;
            }
        }
    return false;
}

bool sol(){
    for(int i=0 ;i<ttl; i++)
        if(A[i]<0){
            memset(vis, false, 10*sizeof(bool));
            if(!dfs(i)) return false;
        }
    for(int i=0; i<10; i++)
        if(B[i] >= 0)
            printf("%c", p[B[i]]);
        else
            printf("_");
    puts("");
    return true;
}

int main(){
    while(init())
        if(!sol())
            puts("!");
    return 0;
}
