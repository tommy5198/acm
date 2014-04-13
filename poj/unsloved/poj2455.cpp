#include<cstdio>
#include<queue>
using namespace std;

void init(){
    scanf("%d%d%d", &n, &p, &t);
    for(int i=0; i<p; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &w);
        L[b][a] = L[a][b] = -w;
        opp[a][b] = opp[b][a] = 0;
    }
}

void sol(){
    queue<int> q;
    
    while(1){
        

    }
}

int main(){
    init();
    sol();
    return 0;
}
