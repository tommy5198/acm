#include<cstdio>

#define MAX 3200
int n, used, k;
int cnt[51];
int stick[64];

bool match(int now, int nowv, int v){
    if(nowv == v){
        //
    }
    if(now == k) return false;
    for(int i=cnt[now]; i>=0; )
}
bool check(int L){
    while(used < n){
        if(!match())
            return false;
    }
    return true;
}
int main(){
    while(scanf("%d", &n), n){
        int ans;
        for(int i=0; i<n; i++){
            scanf("%d", &ans);
            if(cnt[ans] == 0) stick[k++] = ans;
            cnt[ans]++;
        }
        for(ans=1; ans<=MAX; ans++)
            if(check(ans))
                break;
        printf("%d\n", ans);
    }
    return 0;
}
