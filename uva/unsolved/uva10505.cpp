#include<cstdio>
#include<vector>
using namespace std;

void init(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int a, b;
        scanf("%d", &a);
        while(a--){
            scanf("%d", &b);
            v[i].push_back(b);
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
    }
    return 0;
}
