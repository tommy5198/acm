// sort
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Line{
    int L, R;
    bool operator<(const Line &t)const{
        return L < t.L;
    }
}line[100001];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int m, mx, tmp = -1, sum = 0, mxr = -1, mxl = 0;
        scanf("%d", &m);
        for(mx = 0;; mx++){
            scanf("%d%d", &line[mx].L, &line[mx].R);
            if(line[mx].L == 0 && line[mx].R == 0)
                break;
        }
        vector<int> cover;
        sort(line, line+mx);
        for(int i=0; i<mx; i++){
            if(line[i].L > mxl && tmp == -1)
                break;
            if(line[i].L > mxl && tmp != -1){
                mxl = line[tmp].R;
                cover.push_back(tmp);
                tmp = -1;
                i--;
            }
            else if(line[i].R > mxr){
                tmp = i;
                mxr = line[i].R;
                if(mxr >= m){
                    cover.push_back(i);
                    break;
                }
            }
        }
        if(tmp != -1){
            sum = cover.size();
            printf("%d\n", sum);
            for(int i=0; i<sum; i++)
                printf("%d %d\n", line[cover[i]].L, line[cover[i]].R);
        }else
            printf("0\n");
        if(T)
            printf("\n");
    }
    return 0;
}
