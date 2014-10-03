#include<cstdio>

char str[82];
int p[82];

int main(){
    int T, ans, i, j;
    
    scanf("%d", &T);
    while(T--){
        scanf("%s", str+1);
        for(i=2, j=0; str[i]; i++){
            while(j > 0 && str[j+1] != str[i])
                j = p[j];
            if(str[j+1] == str[i])
                j++;
            p[i] = j;
        }
        i--;
        j = i;
        ans = i-p[i];
        while(  i && i != ans ){
            if(ans != i-p[i]){
                ans = j;
                break;
            }
            i = p[i];
        }
        printf("%d\n", ans);
        if(T) puts("");
    }
    return 0;
}
