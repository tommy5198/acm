#include<cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        int r, c, m;
        scanf("%d%d%d", &r, &c, &m);
        int mi = r>=c ? c : r;
        int mx = mi<c ? c : r;
        int nm = r*c - m;
        if(mi*2 > nm){
            :
        }

    }
    return 0;
}
