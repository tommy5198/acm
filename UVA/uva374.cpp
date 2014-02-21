#include<cstdio>
#include<cmath>
#include<cstring>
int tmp[31], b, p, m;

int f(){
    tmp[0] = b % m;
    for(int i=1; i<31; i++){
        tmp[i] =( tmp[i-1] * tmp[i-1])%m;
    }
    int ans = 1;
    for(int i=0; i<31; i++){
        if((1<<i) & p)
            ans = (ans * tmp[i]) % m;
    }
    return ans;
}
int main(){
    while(scanf("%d%d%d", &b, &p, &m) != EOF){
        if(m != 1)
            printf("%d\n", f());
        else if(p == 0 || b == 1)
            printf("0\n");
        else
            printf("1\n");

    }
    return 0;
}
