//back track
#include<cstdio>
#include<cstdlib>
int n, t;
int track[20];
bool ans[20];
bool ed[20];
int Ans;
void DFS(int now, int v){
    if(now == t ){
        if(v <= n && v > Ans){
            Ans = v;
            for(int i=0; i<now; i++)
                ed[i] = ans[i];
        }
        return ;
    }
    ans[now] = true;
    DFS(now+1, v+track[now]);
    ans[now] = false;
    DFS(now+1, v);
}
int main(){
    while(scanf("%d%d", &n, &t) != EOF){
        Ans = -1000000;
        for(int i=0; i<t; i++)
            scanf("%d", &track[i]);
        DFS(0, 0);
        for(int i=0; i<t; i++)
            if(ed[i])
                printf("%d ", track[i]);
        printf("sum:%d\n", Ans);
    }
    return 0;
}
