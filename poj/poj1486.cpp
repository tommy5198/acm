// bimatch
#include<cstdio>
#include<cstring>
#define MAX 26

int n, T;
int x[MAX], y[MAX], a[MAX], b[MAX];
int xmi[MAX], xmx[MAX], ymi[MAX], ymx[MAX];
bool e[MAX][MAX];
bool vis[MAX];
int ma[MAX], mb[MAX];

bool cover(int i, int j){
    return x[i] >=xmi[j] && x[i] <= xmx[j] && y[i] >= ymi[j] && y[i] <= ymx[j];
}

bool init(){
    scanf("%d", &n);
    if(!n) return false;

    for(int i=0; i<n; i++){
        a[i] = b[i] = -1;
        scanf("%d%d%d%d", xmi+i, xmx+i, ymi+i, ymx+i);
    }
    for(int i=0; i<n; i++){
        scanf("%d%d", x+i, y+i);
        for(int j=0; j<n; j++)
            if(cover(i, j)){
                e[i][j] = true;
                if(a[i]<0 && b[j]<0)
                    a[i] = j, b[j] = i;
            }else
                e[i][j] = false;
    }

    return true;
}

bool dfs(int now){
    for(int i=0; i<n; i++)
        if(!vis[i] && e[now][i]){
            vis[i] = true;
            if(b[i]<0 || dfs(b[i])){
                a[now] = i;
                b[i] = now;
                return true;
            }
        }
    return false;
}

int match(){
    int sum = n;
    for(int i=0 ;i<n; i++)
        if(a[i]<0){
            memset(vis, false, sizeof(bool)*n);
            if(!dfs(i)) sum--;
        }
    return sum;
}

void sol(){
    int sum = match();
    int k = 0;
    for(int i=0; i<n; i++)
        if(b[i] >= 0){
            mb[k] = i;
            ma[k++] = b[i];
        }
    bool found = false;
    printf("Heap %d\n", ++T);
    for(int i=0; i<k; i++){
        e[ma[i]][mb[i]] = false;
        memset(a, -1, sizeof(int)*n);
        memset(b, -1, sizeof(int)*n);
        if(match() != sum){
            if(found) printf(" ");
            else found = true;
            printf("(%c,%d)", mb[i]+'A', ma[i]+1);
        }
        e[ma[i]][mb[i]] = true;
    }
    if(!found) puts("none\n");
    else puts("\n");
}

int main(){
    while(init())
        sol();
    return 0;
}
