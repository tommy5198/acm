#include<cstdio>
#include<set>
#define MAX 100000
using namespace std;

struct arrow{
    int num, order;
    bool operator<(const arrow &t)const{
        if(num==t.num)
            return false;
        return order<t.order;
    }

};

arrow target[MAX];
set<arrow> inquiver;
int n, m, c;

bool shoot(int cap){
    int cost = 0;
    inquiver.clear();

    printf("CAP = %d\n", cap);
    for(int i=0; i<m; i++){
        target[i].order = i;
        printf("target = %d\n", target[i].num);
        if(inquiver.find(target[i]) == inquiver.end()){
                printf("target not found");
                for (set<arrow>::iterator it=inquiver.begin(); it!=inquiver.end(); ++it)
                    printf(" %d&%d", it->num, it->order);
                puts("");
            if(inquiver.size() == cap){
                printf("erase %d\n", inquiver.begin()->num);
                inquiver.erase(inquiver.begin());
            }
            cost++;
            if(cost > c)
                return false;
        }else{
            for (set<arrow>::iterator it=inquiver.begin(); it!=inquiver.end(); ++it)
                    printf(" %d&%d", it->num, it->order);
                puts("");
            printf("target = %d found size=%d\n", inquiver.find(target[i])->num, inquiver.size());

            inquiver.erase(target[i]);

        }
        target[i].order = i;
        inquiver.insert(target[i]);
    }
    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &c);
        for(int i=0; i<m; i++)
            scanf("%d", &target[i].num);
        int mid, top = n, low = 1;
        while(top != low){
            mid = (top+low)/2;
            if(shoot(mid))
                top = mid;
            else
                low = mid + 1;
        }
        printf("%d %d\n", shoot(top)?top:-1, top);

    }
    return 0;
}
