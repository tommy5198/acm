#include<cstdio>
#include<cmath>
using namespace std;
int a[1000];

int main(){
    int n, Case = 1;
    while(scanf("%d", &n), n){
        printf("Case %d:\n", Case++);
        int m, qry, sum;
        for(int i=0; i<n; i++)
            scanf("%d", a+i);
        scanf("%d", &m);
        while(m--){
            scanf("%d", &qry);
            sum = -10000000;
            for(int i=0; i<n; i++)
                for(int j=i+1; j<n; j++)
                    if(abs(a[i]+a[j]-qry) < abs(sum - qry))
                        sum = a[i] + a[j];
            printf("Closest sum to %d is %d.\n", qry, sum); 
        }

    }
    return 0;
}
