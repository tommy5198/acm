// bisearch
#include<cstdio>

long long n;
long long sol(long long low, long long up){
    long long mid = (low+up)/2;
    if(low >= up) return low;
    if(mid*(mid+1)/2 > n)
        return sol(low, mid-1);
    else{
        if(low+1 == up){
            if(up*(up+1)/2 > n) return low;
            else return up;
        }
        return sol(mid, up);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lld", &n);
        printf("%lld\n", sol(0, 1414213562));
    }

    return 0;
}
