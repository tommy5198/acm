#include<cstdio>
#include<cstring>
int n;
int num[500000];
int tmp[500000];

long long merge_cnt(int a, int b){
    if(a == b || a == b-1){
       tmp[a] = num[a];

        return 0;
    }

    int mid = (a+b)/2;
     //printf("%d %d %d\n", a, mid, b);
    long long cnt = merge_cnt(a, mid) + merge_cnt(mid, b);
    int ai = a, bi = mid;
    for(int i=a; i<b; i++){
        if(bi != b && (ai == mid || tmp[ai] > tmp[bi]) ){
            num[i] = tmp[bi];
            cnt+=bi-i;
            bi++;
        }else{
            num[i] = tmp[ai];
            ai++;
        }
    }
    for(int i=a; i<b; i++)
        tmp[i] = num[i];

    return cnt;
}
long long sol(){
    memset(tmp, 0, sizeof(tmp));
    return merge_cnt(0, n);
}
int main(){
    while(scanf("%d", &n) != EOF){
        if(!n)
            break;
        for(int i=0; i<n; i++)
            scanf("%d", &num[i]);
        printf("%lld\n", sol());

    }
    return 0;
}
