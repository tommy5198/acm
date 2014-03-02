#include<cstdio>
#include<algorithm>
int main(){
    int num;
    scanf("%d", &num);
    if(num > 0){
        printf("%d", num);
        return 0;
    }
    int mx = -1200000000;
    int last = num%10, belast = num%100;
    mx = std::max(mx, num/10);
    mx = std::max(mx, (num - belast)/10 + last);
    printf("%d", mx);
    return 0;
}
