#include<cstdio>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;

int main(){

    int n;
    while(scanf("%d", &n)!=EOF){
        if(!n)
            break;
        int sum=0;
        pair<int,int> a, b;
        map<pair<int,int>, int> m;
        for(int i=0; i<n; i++){
            scanf("%d%d", &a.first, &a.second);
            b = make_pair(a.second, a.first);
            if(m[b]){
                sum--;
                m[b]--;
            }else{
                sum++;
                m[a]++;
            }
        }
        if(!sum)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
