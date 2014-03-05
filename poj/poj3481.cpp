#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

struct cl{
    int k, p;
    bool operator<(const cl &t)const{
        return p>t.p;
    }
}tmp;

int main(){

    int op;
    set<cl>::iterator itr;
    set<cl> mx, mi;
    while(scanf("%d", &op), op){
        if(op == 1){
            scanf("%d%d", &tmp.k, &tmp.p);
            mx.insert(tmp);
            tmp.p = -tmp.p;
            mi.insert(tmp);
        }else if(op == 2){
            if(mx.empty())
                printf("0\n");
            else{
                itr = mx.begin();
                printf("%d\n", itr->k);
                tmp = *itr;
                mx.erase(tmp);
                tmp.p = -tmp.p;
                mi.erase(tmp);
            }
        }else if(op == 3){
            if(mi.empty())
                printf("0\n");
            else{
                itr = mi.begin();
                printf("%d\n", itr->k);
                tmp = *itr;
                mi.erase(tmp);
                tmp.p = -tmp.p;
                mx.erase(tmp);
            }
        }
    }
    return 0;
}
