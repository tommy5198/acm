//LIS
#include<cstdio>


int main(){
    int n, mx = 0;
    double num[1000];
    int LIS[1000], ldp[1000], rdp[1000];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%lf", num+i);
    LIS[0] = ldp[0] = rdp[n-1] = 1;
    for(int i=1; i<n ;i++){
        LIS[i] = 1;
        for(int j=0; j<i; j++)
            if(num[j]<num[i] && LIS[i]<LIS[j]+1)
                LIS[i] = LIS[j]+1;
        ldp[i] = LIS[i]>ldp[i-1] ? LIS[i] : ldp[i-1];
    }
    LIS[n-1] = 1;
    for(int i=n-2; i>=0 ;i--){
        LIS[i] = 1;
        for(int j=n-1; j>i; j--)
            if(num[j]<num[i] && LIS[i]<LIS[j]+1)
                LIS[i] = LIS[j]+1;
        rdp[i] = LIS[i]>rdp[i+1] ? LIS[i] : rdp[i+1];
    }
    for(int i=0; i<n-1; i++)
	mx = mx>(ldp[i]+rdp[i+1]) ? mx : (ldp[i]+rdp[i+1]);
    printf("%d\n", n-mx);
    return 0;
}
