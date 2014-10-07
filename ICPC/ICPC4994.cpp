#include<cstdio>
#include<cstring>

char movie[61];
char scene[6][11];
bool used[6];
int T, n, len;

void rec(int now, int end, int cnt){
    if(cnt == n){
        len = len>end ? end : len;
        return ;
    }
    for(int i=0; i<n; i++)
        if(!used[i]){
            for(int j=0, k=0; ; k++){
                if(j+k == end){
                    strcat(movie, scene[i]+k);
                    break;
                }
                if(movie[j+k] != scene[i][k])
                    k = -1, j++;
            }
            used[i] = true;
            rec(i, strlen(movie), cnt+1);
            movie[end] = 0;
            used[i] = false;
        }
}
int main(){
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%s", scene[i]);
        len = 100;
        for(int i=0; i<n; i++){
            strcpy(movie, scene[i]);
            used[i] = true;
            rec(i, strlen(movie), 1);
            used[i] = false;
        }
        printf("Case %d: %d\n", ca, len);
    }
    return 0;
}

