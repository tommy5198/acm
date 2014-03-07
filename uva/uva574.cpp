//back track
#include<cstdio>

int t, n, no;
bool yes;
int num[1500];
int cnt[1050];
int ans[1500];
void DFS(int now, int v){
    if(v == t){
        //print
        bool first = true;
        for(int i=0; i<now; i++)
            for(int j = 0; j<ans[i]; j++){
                if(first) printf("%d", num[i]);
                else printf("+%d", num[i]);
                first = false;
                yes = true;
            }
        if(yes)
            printf("\n");
        return ;
    }
    if(now == no) return ;
    //printf("%d %d\n", num[now], v);
    for(int i=cnt[num[now]]; i>=0; i--)
        if(v + i*num[now] <= t){
            ans[now] = i;
            DFS(now+1, v+i*num[now]);
            ans[now] = 0;
        }
}
int main(){
    while(scanf("%d%d", &t, &n), n){
        no = 0;
        yes = false;
        for(int i=0; i<1050; i++) cnt[i] = 0;
        for(int i=0; i<n; i++){
            int x;
            scanf("%d", &x);
            if(!cnt[x]) num[no++] = x;
            cnt[x]++;
        }
        printf("Sums of %d:\n", t);
        DFS(0, 0);
        if(!yes) printf("NONE\n");
    }
    return 0;
}
