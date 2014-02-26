#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        int m, n;
        int a[30001] = {0}, u[30001] = {0};
        multiset<int> mst;
        multiset<int>::iterator itr;
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(int i=0; i<m; i++)
            scanf("%d", &u[i]);
        for(int i=0, j=0; i<n; i++){
            mst.insert(a[i]);
            if(j != 0 && a[i] < *itr)
                --itr;
            while(i == u[j] - 1){
                if(j == 0)
                    itr = mst.begin();
                else
                    ++itr;
                printf("%d\n", *itr);
                j++;
            }
        }
        if(T)
            printf("\n");
    }
    return 0;
}
