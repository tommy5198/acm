//topsort
#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int> child[101];
int pre[101];
bool ok;
void topsort(){

    for(int i=1; i<=n; i++)
        if(!pre[i]){
            pre[i] = -1;
            for(int j=0; j<child[i].size(); j++)
                pre[child[i][j] ]--;
            if(ok) printf(" ");
            printf("%d", i);
            ok = true;
            topsort();
        }
}
int main(){
    scanf("%d", &n);
    ok = false;
    for(int i=1; i<=n; i++){
        int tmp;
        while(scanf("%d", &tmp), tmp){
            child[i].push_back(tmp);
            pre[tmp]++;
        }
    }
    topsort();
    puts("");
    return 0;
}
