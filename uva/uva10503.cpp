//back track , && > || JIZZ
#include<cstdio>

int n, m;
int domino[14][2];
int ans[16][2];
bool used[14];

void swap(int idx){
    int t = domino[idx][0];
    domino[idx][0] = domino[idx][1];
    domino[idx][1] = t;
}
bool sol(int now){
    if(now > n){
        if(ans[now-1][1] == ans[now][0])
            return true;
        else
            return false;
    }
    int next = -1;
    for(int i=0; i<m ;i++)
        if(!used[i] &&( ans[now-1][1] == domino[i][0] || ans[now-1][1] == domino[i][1]) ){
            if(ans[now-1][1] == domino[i][1])
                swap(i);
            if(next == domino[i][1]) continue;
            next = domino[i][1];
            used[i] = true;
            ans[now][0] = domino[i][0];
            ans[now][1] = domino[i][1];
            if(sol(now+1)) return true;
            used[i] = false;
        }
    return false;
}
int main(){
    freopen("t.in", "r", stdin);
    int T = 1;
    while(scanf("%d", &n), n){
        scanf("%d", &m);
        scanf("%d%d%d%d", &ans[0][0], &ans[0][1], &ans[n+1][0], &ans[n+1][1]);
        for(int i=0; i<m; i++){
            scanf("%d%d", &domino[i][0], &domino[i][1]);
            used[i] = false;
        }
            //printf("%d ", T++);
        if(sol(1))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
