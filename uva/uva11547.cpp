#include<cstdio>
#include<cstdlib>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", abs(((567*n/9 + 7492)*235/47 - 498)/10) %10 );
    }
    return 0;
}
