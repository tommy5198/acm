// kmp range query rank
#include<cstdio>

int n, k, s, cnt;
int cow[100001], pcow[25001];
int rank[100001][26], prank[25001][26];
int p[25001], ans[100000];

void init(){
    scanf("%d%d%d", &n, &k, &s);
    
    for(int i=1; i<=n; i++){
        scanf("%d", cow+i);
        for(int j=1; j<=cow[i]; j++)
            rank[i][j] = rank[i-1][j];
        for(int j=cow[i]+1; j<=s; j++)
            rank[i][j] = rank[i-1][j]+1;
    }
    
    for(int i=1; i<=k; i++){
        scanf("%d", pcow+i);
        for(int j=1; j<=pcow[i]; j++)
            prank[i][j] = prank[i-1][j];
        for(int j=pcow[i]+1; j<=s; j++)
            prank[i][j] = prank[i-1][j] + 1; 
    }

    for(int i=1; i<=k; i++){
        int tmp = 1;
        for(int j=pcow[i]; j; j--)
            tmp = prank[k][j]-prank[k][j-1] ? tmp+1 : tmp;
        pcow[i] = tmp;
    }
}

int cmp(int a, int b){
    if(a > b)
        return 1;
    else if(a == b)
        return 0;
    return -1;
}

void prefix(){
    
    p[1] = p[2] = 1;
    for(int i=3, j=1; i<=k; i++){
        while(j > 1 && cmp(pcow[j+1], pcow[j]) != cmp(pcow[i], pcow[i-1]))
            j = p[j];
        if(cmp(pcow[j+1], pcow[j]) == cmp(pcow[i], pcow[i-1]))
            j++;
        p[i] = j;
    }
}

int getrank(int j, int i){
    if(i-j+k-1 > n)
        return -1;
    int tmp = 1;
    for(int x=cow[i]; x; x--)
        if(rank[i-j+k-1][x]-rank[i-j-1][x] - rank[i-j+k-1][x-1] + rank[i-j-1][x-1])
             tmp++;
    return tmp;
}

void kmp(){
    
    if(k == 1){
        printf("%d\n", n);
        for(int i=1; i<=n; i++)
            printf("%d\n", i);
        return ;
    }

    prefix();
    cnt = 0;
    for(int i=2, j=1; i<=n; i++){
        int tmp = getrank(j, i);
        while(j > 1 && pcow[j+1] != tmp){
            j = p[j];
            tmp = getrank(j, i);
        }
        if(j==1 && getrank(0, i-1) != pcow[1])
            continue;
        
        if(pcow[j+1] == tmp)
            j++;
        if(j == k){
            j = p[j];
            ans[cnt++] = i-k+1;
        }
    }

    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++)
        printf("%d\n", ans[i]);
}

int main(){
    init();
    kmp();
    return 0;
}
