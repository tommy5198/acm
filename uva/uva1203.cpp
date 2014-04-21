#include<cstdio>
#include<queue>
using namespace std;

struct reg{
    int qnum;
    int cur;
    int period;
    int order;
    bool operator<(const reg &t)const{
        if(cur == t.cur)
            return qnum > t.qnum;
        return cur > t.cur;
    }
}regs, tmp;
int p[1000];
int main(){
    char str[9];
    int k = 0;
    priority_queue<reg> pq;
    while(scanf("%s", str), str[0] != '#') {
        scanf("%d%d", &regs.qnum, &regs.period);
        regs.cur = regs.period;
        regs.order = k++;
        pq.push(regs);
    }
    scanf("%d", &k);
    while(k--){
        tmp = pq.top(); pq.pop();
        printf("%d\n", tmp.qnum);
        tmp.cur += tmp.period;
        pq.push(tmp);
    }
    return 0;
}
