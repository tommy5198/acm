//back track , god damn IO
#include<cstdio>
#include<cstring>
char paper[15][31];
int n, a, b;
bool used[15];
int ans[15];
void DFS(int now, int d, int v){
    if(d == v){
        //print
        for(int i=0; i<d; i++){
            if(i) printf(", ");
            printf("%s", paper[ans[i]]);
        }
        printf("\n");
        return ;
    }
    while(now < n){
        ans[d] = now;
        DFS(++now, d+1, v);
    }
}
int main(){
    int T;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    getchar();getchar();
    while(T--){
        n = 0;
        char req[10];
        gets(req); //printf("%s\n", req);
        int stat = sscanf(req, "%d%d", &a, &b);
        while(gets(paper[n]) && paper[n][0]) n++;
        if(!stat){
            a = 1;
            b = n;
        }else if(stat == 1)
            b = a;
        //printf("==%d==\n", n);
        for(int i=a; i<=b; i++){
            printf("Size %d\n", i);
            DFS(0, 0, i);
            printf("\n");
        }
        if(T) printf("\n");
    }
    return 0;
}
