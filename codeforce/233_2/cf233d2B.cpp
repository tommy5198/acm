#include<cstdio>

int main(){
    int n;
    char ball[52];
    long long B[50], sum = 0;
    for(int i=0; i<50; i++){
        B[i] = sum + 1;
        sum += B[i];
    }
    sum = 0;
    scanf("%d%s", &n, ball);
    for(int i=0; i<n; i++)
        if(ball[i] == 'B')
            sum += B[i];

    printf("%I64d", sum);
    return 0;
}
