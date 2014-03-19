#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int p, t;
string ppl[101];
map<string, bool> m;

void init(){
    scanf("%d%d", &p, &t);
    m.clear();
    for(int i=1; i<=p; i++)
        ppl[i].clear();
}

int sol(){
    char cstr[10];
    int a, b;
    getchar();
    while(gets(cstr) && cstr[0]){
        sscanf(cstr, "%d%s", &a, &b);
        puts(cstr);
        getchar();
        ppl[a].push_back(b);
    }
    for(int i=1; i<=p; i++){
        sort(ppl[i].begin(), ppl[i].end());
        m[ppl[i]] = true;
    }
    return m.size();
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        printf("%d\n", sol());
        if(T) puts("");
    }
    return 0;
}
