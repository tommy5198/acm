#include<cstdio>

char lower(char c) {
    return c >= 'a' ? c : c - 'A' + 'a';
}

char name[1000][1001];
int v[1000];
char good[31];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i=0; i<n; i++) {
            scanf("%s", name[i]);
            v[i] = 0;
        }
        for(int i=0; i<m; i++) {
            scanf("%s", good);
            for(int j=0, g = 0; j<n; j++, g = 0) {
                for(int k=0; name[j][k]; k++) {
                    if(lower(name[j][k]) == lower(good[g]))
                        g++;
                    if(!good[g]) break;
                }
                if(!good[g])
                    v[j]++;
            }
        }
        for(int i=0; i<n; i++)
            printf("%d\n", v[i]);
    }
    return 0;
}
