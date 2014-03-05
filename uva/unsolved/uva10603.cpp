//Dijkstra from first state(0, 0, C)
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 1000000000
int jug[3], sum[201][201][201], D, ansd;
struct Sum{
    int sum, j[3];
    bool operator<(const Sum &t)const{
        return sum>t.sum;
    }
}TMP;
void init(){
    for(int i=0; i<201; i++)
        for(int j=0; j<201; j++)
            for(int k=0; k<201; k++)
                sum[i][j][k] = INF;
    sum[0][0][jug[2]] = 0;
    ansd = -1;
}
int reach(Sum s){
    int tmp[3] = {s.j[0]-D, s.j[1]-D, s.j[2]-D};
    if(!tmp[0] || !tmp[1] || !tmp[2])
        return 0;
    sort(tmp, tmp+3);
    int i;
    for(i=0; i<3 && tmp[i] < 0; i++);
    return i>0?tmp[i-1]:tmp[0];

}
Sum Dijkstra(){
    Sum now, ans;
    int tmp[3];
    priority_queue<Sum> pq;
    TMP.sum = 0;
    TMP.j[0] = 0; TMP.j[1] = 0; TMP.j[2] = jug[2];
   // printf("%d\n", reach(TMP));
    pq.push(TMP);
    while(!pq.empty()){
        now = pq.top();
        int result = reach(now);
        if(!result){
                ansd = D;
            return now;
        }else if(result < 0 && ansd < D+result){
            ansd = D+result;
            ans = now;
        }
        for(int i=0; i<3; i++)
            tmp[i] = now.j[i];
        pq.pop();
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(i != j){

                    int delta = min(jug[j] - now.j[j], now.j[i]);
                    tmp[i] -= delta; tmp[j] += delta;
                    //printf("%d %d %d-\n", tmp[0], tmp[1], tmp[2]);
                    if(sum[tmp[0]][tmp[1]][tmp[2]] > now.sum + delta){
                        TMP.sum = sum[tmp[0]][tmp[1]][tmp[2]] = now.sum + delta;
                        for(int k=0; k<3; k++)
                            TMP.j[k] = tmp[k];
                        pq.push(TMP);
                    }
                    for(int k=0; k<3; k++)
                        tmp[k] = now.j[k];

                }
    }
    return ans;
}

/*
int sol(){
    int S = INF;
    for(int i=0; i<=jug[0]; i++)
        for(int j=0; j<=jug[1]; j++)
            S = min(S, sum[i][j][D]);
    for(int i=0; i<=jug[0]; i++)
        for(int j=0; j<=jug[2]; j++)
            S = min(S, sum[i][D][j]);
    for(int i=0; i<=jug[1]; i++)
        for(int j=0; j<=jug[2]; j++)
            S = min(S, sum[D][i][j]);
    if(S != INF)
        return S;
    else
        D--;
    return sol();
}*/
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &jug[0], &jug[1], &jug[2], &D);
        init();
        TMP = Dijkstra();

        printf("%d %d\n", TMP.sum, ansd);
    }
    return 0;
}
