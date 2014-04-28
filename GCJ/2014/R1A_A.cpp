#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, l;
int oz[40], gz[40];
long long ov[150], gv[150];
void init(){
    scanf("%d%d", &n, &l);
    memset(oz, 0, sizeof(oz));
    memset(gz, 0, sizeof(gz));
    for(int i=0; i<n; i++){
        getchar();
        ov[i] = 0;
        for(int j=0; j<l; j++){
            if(getchar() == '0'){
                ov[i] *= 2;
                oz[j]++;
            }else
                ov[i] = ov[i]*2+1;
        }
    }
    for(int i=0; i<n; i++){
        getchar();
        gv[i] = 0;
        for(int j=0; j<l; j++){
            if(getchar() == '0'){
                gz[j]++;
                gv[i] *= 2;
            }else
                gv[i] = gv[i]*2 + 1;
        }
    }
}

int sol(){
    int ans = 0;
    long long tmp = 1, xr = 0;
    for(int i=0; i<l; i++){

        if(oz[i] == gz[i]){
            if(oz[i]+gz[i] == n)
                same |= tmp<<(l-i-1);
        }
        if(oz[i]+gz[i] == n){
            ans++;
            xr |= tmp<<(l-i-1);
        }else
            return -1;
    }
    for(int i=0; i<n; i++)
        ov[i] ^= xr;
    sort(ov, ov+n);
    sort(gv, gv+n);
    for(int i=0; i<n; i++)
        if(ov[i] != gv[i])
            return -1;
    return ans;

}
int main(){
    int T;
    scanf("%d", &T);
    for(int tm=1; tm<=T; tm++){
        init();
        int result = sol();
        if(result == -1)
            printf("Case #%d: NOT POSSIBLE\n", tm);
        else
            printf("Case #%d: %d\n", tm, result);
    }
    return 0;
}
