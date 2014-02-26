#include<cstdio>
#include<queue>
#include<set>
using namespace std;

struct NODE{
    int num;
    bool operator<(const NODE &t) const{
        return num < t.num;
    }
};

int main(){

    int n;
    while(scanf("%d", &n), n){

        multiset<NODE> mst;
        NODE tmp,tmp2;
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d", &tmp.num);
            mst.insert(tmp);
        }

        while(!mst.empty()){
            tmp.num=mst.begin()->num;
            mst.erase(mst.begin());
            if(mst.empty())
                break;
            tmp.num+=mst.begin()->num;
            mst.erase(mst.begin());
            mst.insert(tmp);
            ans+=tmp.num;
        }

        printf("%d\n", ans);
    }
    return 0;
}



