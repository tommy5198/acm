#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
int n, nc;
struct ST{
    char *sub;
    bool operator<(const ST &t)const{
        for(int i=0; i<n; i++)
            if(sub[i] != t.sub[i])
                return sub[i] < t.sub[i];
        return false;
    }
};

char str[16000001], *sptr;
set<ST> st;
ST tmp;

int main(){
    while(scanf("%d%d", &n, &nc) != EOF){
        st.clear();
        getchar();
        tmp.sub = str;
        for(int i=0; i<n-1; i++)
            str[i] = getchar();
        for(int i=n-1; (str[i]=getchar()) != '\n'; i++) {
            st.insert(tmp);
            tmp.sub++;
        }
        printf("%d\n", (int)st.size());

    }
    return 0;
}
