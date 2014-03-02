#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n, s, cow[20000];
    scanf("%d%d", &n, &s);
    for(int i=0; i<n; i++)
        scanf("%d", &cow[i]);
    sort(cow, cow+n);
    int i=0, j=n-1, ans = 0;
    while(i < j){
        if(cow[j] >= s)
            j--;
        else if(cow[i] + cow[j] > s){
            ans += i;
            j--;
        }else
            i++;
    }
    ans += i*(i-1)/2;
    j = i;
    i--;
    while(i > 0 && cow[j] + cow[i] > s) i--;
    ans += i+1;
    printf("%d\n", ans);
    return 0;
}
