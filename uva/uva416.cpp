//back track
#include<cstdio>
#include<cstring>

int n;
bool burn[7];
char cond[11][8];
char seg[10][8] = {"YYYYYYN",
                        "NYYNNNN",
                        "YYNYYNY",
                        "YYYYNNY",
                        "NYYNNYY",
                        "YNYYNYY",
                        "YNYYYYY",
                        "YYYNNNN",
                        "YYYYYYY",
                        "YYYYNYY"};
bool count(int nowc, int now){
    if(now == n)
        return true;
    for(int j=0; j<7; j++){
        if(cond[now][j] == 'N' && seg[nowc][j] == 'Y')
            burn[j] = true;
        else if(cond[now][j] == 'Y' && seg[nowc][j] == 'N')
            return false;
        else if(cond[now][j] == 'Y' && burn[j])
            return false;
    }

    return count(nowc-1, now+1);
}
bool match(){
    for(int i=9; i>=n-1; i--){
        int j;
        for(j=0; j<7; j++){
            if(cond[0][j] == 'N' && seg[i][j] == 'Y')
                burn[j] = true;
            else if(cond[0][j] == 'Y' && seg[i][j] == 'N')
                break;
            else
                burn[j] = false;
        }
        if(j == 7 && count(i-1, 1))
            return true;
    }
    return false;
}
int main(){
    freopen("t.in", "r", stdin);
    while(scanf("%d", &n), n){
        for(int i=0; i<n; i++)
            scanf("%s", cond[i]);
        if(match())
            puts("MATCH");
        else
            puts("MISMATCH");
    }
    return 0;
}
