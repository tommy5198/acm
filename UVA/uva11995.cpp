#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int op, x, stat = 7;
        stack<int> stk;
        queue<int> q;
        priority_queue<int> pq;
        while(n--){
            scanf("%d%d", &op, &x);
            if(!stat)
                continue;
            if(op == 1){
                stk.push(x);
                q.push(x);
                pq.push(x);
            }else{
                if(stk.empty() || stk.top() != x)
                    stat &= 6;
                else
                    stk.pop();
                if(q.empty() || q.front() != x)
                    stat &= 5;
                else
                    q.pop();
                if(pq.empty() || pq.top() != x)
                    stat &= 3;
                else
                    pq.pop();
            }
        }
        if(!stat)
            puts("impossible");
        else if(stat == 1)
            puts("stack");
        else if(stat == 2)
            puts("queue");
        else if(stat == 4)
            puts("priority queue");
        else
            puts("not sure");
    }
    return 0;
}
