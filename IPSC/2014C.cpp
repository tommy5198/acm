#include<cstdio>
#include<map>
using namespace std;

map<int, bool> mp;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, a, ft=0;
        scanf("%d", &n);
        mp.clear();
        while(n--){
            scanf("%d", &a);
            if(!mp[a]){
                mp[a] = true;
                if(ft) printf(" ");
                else ft=1;
                printf("%d", a);
            }
        }
        puts("");
    }
    return 0;
}
