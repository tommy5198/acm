#include<cstdio>
#include<queue>
using namespace std;

struct plank{
    int L;
    bool operator<(const plank &t)const{
        return L > t.L;
    }
}tmp;
int main(){
    int n;
    long long sum=0;
    priority_queue<plank> pq;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &tmp.L);
        pq.push(tmp);
    }
    while(!pq.empty()){
        tmp.L = 0;
        tmp.L += pq.top().L;
        pq.pop();
        if(pq.empty())
            break;
        tmp.L+=pq.top().L;
        pq.pop();
        sum += tmp.L;
        pq.push(tmp);
    }
    printf("%lld\n", sum);
    return 0;
}
