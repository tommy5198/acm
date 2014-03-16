#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    double x, y;
    bool operator<(const node &t)const{
        if(x != t.x)
            return x<t.x;
        return y<t.y;
    }
    bool operator!=(const node &t)const{
        return x!=t.x||y!=t.y;
    }
}tmp, dot[1000];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, ans = 0;
        vector<node> v;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%lf%lf", &dot[i].x, &dot[i].y);
            for(int j=i-1; j>=0; j--){
                tmp.x = (dot[i].x+dot[j].x)/2;
                tmp.y = (dot[i].y+dot[j].y)/2;
                v.push_back(tmp);
            }
        }
        sort(v.begin(), v.end());
        tmp = v[0];
        int cnt = 1;
        for(int i=1; i<v.size(); i++){
            if(tmp != v[i]){
                ans += cnt*(cnt-1)/2;
                tmp = v[i];
                cnt = 1;
            }else
                cnt++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
