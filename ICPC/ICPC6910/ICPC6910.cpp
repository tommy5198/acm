#include<cstdio>

struct Q{
    char qry[2];
    int a, b;
};

Q query[5000];
int root[20001], oroot[20001];
int cut[20001];
bool ans[5000];

int findr(int x){
    return !root[x] ? x : root[x]=findr(root[x]);
}
int main(){
    int T, ca = 1;
    scanf("%d", &T);
    while(T--){
        int n, m, ai = 0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n ;i++){
            scanf("%d", root+i);
            oroot[i] = root[i];
            cut[i] = -1;
        }
        for(int i=0; i<m; i++){
            scanf("%s", query[i].qry);
            if(query[i].qry[0] == 'Q')
                scanf("%d%d", &query[i].a, &query[i].b);
            else{
                scanf("%d", &query[i].a);
                cut[query[i].a]++;
                root[query[i].a] = 0;
            }
        }
        for(int i=m-1; ~i; i--){
            if(query[i].qry[0] == 'Q')
                ans[ai++] = findr(query[i].a) == findr(query[i].b);
            else if(cut[query[i].a])
                cut[query[i].a]--;
            else
                root[query[i].a] = oroot[query[i].a];
        }
        printf("Case #%d:\n", ca++);
        for(int i=ai-1; ~i; i--)
            puts(ans[i] ? "YES" : "NO");
    }

    return 0;
}
