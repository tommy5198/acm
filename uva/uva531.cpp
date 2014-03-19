//LCS
#include<cstdio>
#include<cstring>
#include<algorithm>

char str[2][102][31];
int len[2];
int pre[102][102];
int cnt[102][102];
int ans[102];
bool init(){
    for(int i=0; i<2; i++){
        for(int j=1; j<102; j++){
            if(scanf("%s", str[i][j]) == EOF)
                return false;
            if(str[i][j][0] == '#'){
                len[i] = j;
                break;
            }
        }
    }
    return true;
}

void sol(){
    for(int i=0; i<len[0]; i++){
        for(int j=0; j<len[1]; j++){
            if(!i || !j) cnt[i][j] = 0;
            else if(strcmp(str[0][i], str[1][j])){
                cnt[i][j] = std::max(cnt[i-1][j], cnt[i][j-1]);
                if(cnt[i][j] == cnt[i-1][j]) pre[i][j] = -1;
                else pre[i][j] = 1;
            }else{
                cnt[i][j] = cnt[i-1][j-1] + 1;
                pre[i][j] = 0;
            }
        }
    }
    bool f = false;
    int k = 0;
    for(int i=len[0]-1, j=len[1]-1; i&&j; i--, j--){
        if(!pre[i][j])
            ans[k++] = i;
        else if(pre[i][j]^1)
            j++;
        else
            i++;
    }
    
    for(int i=k-1; i>=0; i--){
        printf("%s", str[0][ans[i]]);
        if(i) printf(" ");
    }
    puts("");
}

int main(){
    while(init())
        sol();
    return 0;
}
