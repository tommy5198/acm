// substr match
#include<cstdio>
#include<cstring>

char dna[10][65];
int n;

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s", dna[i]);
}

void sol(){
    bool end = false;
    char ans[65];
    for(int i=0; i<60-2 && !end; i++)
        for(int j=0; j<=i; j++){
            int pre = dna[0][j+60-i];
            int k = 1;
            dna[0][j+60-i] = 0;
            while(k<n && strstr(dna[k], dna[0]+j))
                k++;
            if(k == n){
                if(!end || strcmp(ans, dna[0]+j) > 0)
                    strcpy(ans, dna[0]+j);
                end = true;
            }
            dna[0][j+60-i] = pre;
        }
    if(end)
        printf("%s\n", ans);
    else
        puts("no significant commonalities");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        sol();
    }
    return 0;
}
