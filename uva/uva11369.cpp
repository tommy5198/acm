#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, tmp, ans = 0;
        vector<int> v;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &tmp);
            v.push_back(-tmp);
        }
        sort(v.begin(), v.end());
        for(int i=2; i<v.size(); i+=3)
            ans += -v[i];
        printf("%d\n", ans);
    }
    return 0;
}
