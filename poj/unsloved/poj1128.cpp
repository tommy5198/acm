#include<cstdio>
int n, m, k;
int cha[26][2][2];
char pic[31][31];
char sbl[26];
bool v[26][26];
void init(){
    char c;
    k = 0;
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            c = getchar();
            pic[i][j] = c;
            if(c != '.'){
                if(cha[c - 'A'][0][0] != -1) sbl[k++] = c;
                cha[c - 'A'][0][0] = min(cha[c - 'A'][0][0], i);
                cha[c - 'A'][0][1] = min(cha[c - 'A'][0][1], j);
                cha[c - 'A'][1][0] = max(cha[c - 'A'][1][0], i);
                cha[c - 'A'][1][1] = max(cha[c - 'A'][1][1], j);
            }
        }
        getchar();
    }
}

void check(){
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        if(pic[i][j] != '.'){
            for(int idx = 0; idx<k; idx++){
                if(colli(cha[idx], i, j))
                    v[ pic[i][j] - 'A' ][cha[idx] - 'A'] = true;
            }
        }
}
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        check();
    }
    return 0;
}
