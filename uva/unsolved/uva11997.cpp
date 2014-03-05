#include<cstdio>
#include<queue>
using namespace std;

int main(){
    int k, tmp;
    while(scanf("%d", &k) != EOF){
        priority_queue<int> pq[750];
        int TOP[750];
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++){
                scanf("%d", &tmp);
                pq[i].push(-tmp);
            }

    }
}
