#include<cstdio>

int num[1001];
int n;

int bubble(){
    int cnt = 0;
    for(int i=1; i<n; i++){
        for(int j=i; j>0 && num[j-1] > num[j]; j--){
            int t = num[j];
            num[j] = num[j-1];
            num[j-1] = t;
            cnt++;
        }
    }
    return cnt;
}

void init(){
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);
}

void sol(){
    init();
    printf("Minimum exchange operations : %d\n", bubble());
}
int main(){
    while(scanf("%d", &n) != EOF)
        sol();
    return 0;
}
