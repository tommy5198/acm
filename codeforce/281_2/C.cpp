#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n, m, i, j, tmp;
    int a[200000], b[200000];
    int A = 0, B = 0;
    int ans=-1, ansA=0, ansB=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    scanf("%d", &m);
    for(int i=0; i<m; i++)
        scanf("%d", b+i);
    sort(a, a+n);
    sort(b, b+m);
    for(i=n-1, j=m-1; ~i && ~j;){
        if(a[i] > b[j])
            A++, i--;
        else if(a[i] < b[j])
            B++, j--;
        else
            A++, B++, i--, j--;
        tmp = A*3+(n-A)*2 - B*3 + (m-B)*2;
        if(ans <= tmp){
            ansA = A*3+(n-A)*2;
            ansB = B*3 + (m-B)*2;
            ans = ansA + ansB;
        }
    }
    if(i >= 0){
        ansA += i+1;
        ansB = m*3;
    }
    printf("%d:%d\n", ansA, ansB);

    return 0;
}
