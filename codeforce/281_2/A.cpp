#include<cstdio>

int time[100], player[100];
int cnt[2][100][2];
bool ignore[2][100];
char team[100][3];
char card[100][3];
int n;

int main(){
    char tname[2][21];
    scanf("%s%s", tname[0], tname[1]);
    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf("%d%s%d%s", time+i, team[i], player+i, card[i]);
        if(ignore[team[i][0]=='a'][player[i]]) continue;
        cnt[team[i][0]=='a'][player[i]][card[i][0]=='y']++;
        if(cnt[team[i][0]=='a'][player[i]][1] == 2 || cnt[team[i][0]=='a'][player[i]][0] == 1){
            printf("%s %d %d\n", tname[team[i][0]=='a'], player[i], time[i]);
            ignore[team[i][0]=='a'][player[i]] = true;
        }
    }

    return 0;
}
