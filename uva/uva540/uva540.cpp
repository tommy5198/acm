// easy queue
#include<cstdio>
#include<queue>
using namespace std;

queue<int> Q[1001];
int team[1000000];

void clear(int x){
    for(int i=0; i<=x; i++)
        while(!Q[i].empty()) Q[i].pop();
}
int main(){
    int T, ca = 1;
    while(scanf("%d", &T), T) {
        clear(T);
        for(int i=1; i<=T; i++) {
            int tm;
            scanf("%d", &tm);
            while(tm--){
                int tmp;
                scanf("%d", &tmp);
                team[tmp] = i;
            }
        }
        char cmd[10];
        printf("Scenario #%d\n", ca++);
        while(scanf("%s", cmd), cmd[0] != 'S') {
            if(cmd[0] == 'E') {
                int tmp;
                scanf("%d", &tmp);
                if(Q[team[tmp]].empty())
                    Q[0].push(team[tmp]);
                Q[team[tmp]].push(tmp);
            }else{
                int fteam = Q[0].front();
                printf("%d\n", Q[fteam].front());
                Q[fteam].pop();
                if(Q[fteam].empty())
                    Q[0].pop();
            }
        }
        puts("");
    }
    return 0;
}
