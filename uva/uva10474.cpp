#include<cstdio>
#include<cstring>

int n, q;
int num[10001], sum[10001];

bool init(){
    scanf("%d%d", &n, &q);
    if(!n && !q) return false;
    int pre = 1000000;
    int mx = 0;
    memset(num, 0, sizeof(num));
    memset(sum, 0, sizeof(sum));
    while(n--){
        int a;
        scanf("%d", &a);
        pre = pre<a ? pre : a;
        mx = mx>a ? mx : a;
        num[a]++;
    }
    sum[pre] = 0;
    for(int i=pre+1; i<=mx; i++)
        if(num[i]){
            sum[i] = num[pre] + sum[pre];
            pre = i;
        }
    return true;
}

void sol(int T){
    printf("CASE# %d:\n", T);
    while(q--){
        scanf("%d", &n);
        if(num[n])
            printf("%d found at %d\n", n, sum[n]+1);
        else
            printf("%d not found\n", n);
    }
}
int main(){
    for(int i=1; init(); i++)
        sol(i);
    return 0;
}
