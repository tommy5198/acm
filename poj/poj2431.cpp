//priority queue
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool mode;
struct Stop{
    int dis, fuel;
    //Stop(int i, int j){dis = i; fuel = j;}
    bool operator<(const Stop &t)const{
        if(mode)
            return dis > t.dis;
        return fuel < t.fuel;
    }
}tmp;
int main(){
    int n;
    vector<Stop> v;
    priority_queue<Stop> pq;
    mode = true;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &tmp.dis, &tmp.fuel);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    mode = false;
    scanf("%d%d", &tmp.dis, &tmp.fuel);
    int cnt = 0, vi = 0;
    tmp.dis -= tmp.fuel;
    while(tmp.dis > 0){

        for(;vi < v.size() && v[vi].dis >= tmp.dis; vi++) pq.push(v[vi]);
        if(pq.empty()){
            cnt = -1;
            break;
        }
        tmp.dis -= pq.top().fuel;
        //printf("%d ", tmp.dis);
        pq.pop();
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
