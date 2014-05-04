#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int n, k, sum;
int cnt[101][101];
char c[101][101];
char str[101];

void init(){
    scanf("%d", &n);
    sum = 0;
    for(int i=0; i<n; i++){
        scanf("%s", str);
        c[i][0] = str[0];
        k = 0;
        cnt[i][0] = 1;
        for(int j=1; str[j]; j++){
            if(str[j] == c[i][k])
                cnt[i][k]++;
            else{
                c[i][++k] = str[j];
                cnt[i][k] = 1;
            }
        }   
        c[i][++k] = 0;
    }
}

bool sol(){
    for(int i=1; i<n; i++){
        if(strcmp(c[i], c[i-1]))
            return false;
    }
    for(int i=0; i<k; i++){
        double tmp = 0;
        int t;
        for(int j=0; j<n; j++)
            tmp += cnt[j][i];
        tmp = tmp/n + 0.5;
        t = tmp;
        for(int j=0; j<n; j++)
            sum += abs(t-cnt[j][i]);
    }
    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        if(sol())
            printf("Case #%d: %d\n", i, sum);
        else
            printf("Case #%d: Fegla Won\n", i);
    }
    return 0;
}
