#include<cstdio>

int n;
int num[100001], LIS[100001];

bool init(){
    scanf("%d", num);
    if(num[0] == -1) return false;
    n = 1;
    while(scanf("%d", num+n), num[n]!=-1) n++;
    return true;
}

int sol(){
    int mx = 0;
    for(int i=0; i<n; i++){
        LIS[i] = 1;
        for(int j=0; j<i; j++)
            if(num[j]>=num[i] && LIS[i]<LIS[j]+1)
                LIS[i] = LIS[j]+1;
        mx = mx > LIS[i] ? mx : LIS[i];
    }
    return mx;
}
int main(){
    for(int i=1; init(); i++){
        if(i != 1) puts("");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", i, sol());
    }
    return 0;
}
