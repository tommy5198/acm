#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m) return false;
    for(int i=1; i<=n; i++){
        char str[16];
        int a;
        scanf("%s", str);
        for(char c=getchar(); c==' '; c=getchar()){
            scanf("%d", &a);
            cap[n+a][i] = 1;
        }
    }
}
int main(){

    return 0;
}
