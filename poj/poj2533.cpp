//LIS
#include<cstdio>

int n;
int num[1000];
int LIS[1000];
void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", num+i);
}

int sol(){
    int mx = 0;
    for(int i=0; i<n; i++){
        LIS[i] = 1;
        for(int j=0; j<i; j++)
            if(num[j]<num[i] && LIS[j]+1>LIS[i])
                LIS[i] = LIS[j]+1;
        mx = mx>LIS[i] ? mx : LIS[i];
    }
    return mx;
}
int main(){
    init();
    printf("%d\n", sol());
    return 0;
}
