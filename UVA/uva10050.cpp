#include<cstdio>
#include<cstring>
int main(){
    bool day[3651];
    int T, p, n, sum, tmp;
    scanf("%d", &T);
    while(T--){
        memset(day, false, sizeof(day));
        sum = 0;
        scanf("%d%d", &n, &p);
        for(int i=0; i<p; i++){
            scanf("%d", &tmp);
            for(int j=1; j<=n; j++)
                if(j % 7 != 6 && j % 7 != 0)
                    if(j % tmp == 0 && !day[j]){
                        //printf(" %d\n", j);
                        day[j] = true;
                        sum++;
                    }
        }
        printf("%d\n", sum);
    }
    return 0;
}
