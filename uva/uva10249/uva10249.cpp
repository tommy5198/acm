// sort
#include<cstdio>
#include<algorithm>
using namespace std;

struct TB {
    int value, idx;
    bool operator<(const TB &t)const{
        return value > t.value;
    }
};
int ans[70][50];
int team[70];
TB table[50];

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m), n) {
        int idx = 0;
        for(int i=0; i<n; i++)
            scanf("%d", team + i);

        for(int i=0; i<m; i++) {
            scanf("%d", &table[i].value);
            table[i].idx = i;
        }

        for(int i=0; i<n; i++) {
            idx = 0;
            sort(table, table+m);
            for(int j=0; j<m && idx < team[i]; j++, idx++)
                if(table[j].value--)
                    ans[i][idx] = table[j].idx+1;
                else
                    break;
            if(idx != team[i] && (idx= -1) )
                break;

        }
        if(~idx) {
             puts("1");
            for(int i=0; i<n; i++) {
                for(int j=0; j<team[i]; j++)
                    printf("%d ", ans[i][j]);
                puts("");
            }
        } else
            puts("0");

    }
    return 0;
}
