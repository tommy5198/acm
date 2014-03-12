//topsort , newline at end of output
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

int pre[28], k;
vector<int> v[28];
map<char, int> m;
char c[28];

void init(){
    //freopen("t.in", "r", stdin);
    k = 1;
    m.clear();
    int rev = 1;
    char str[2][21];
    scanf("%s", str[0]);
    while(scanf("%s", str[rev]), str[rev][0] != '#'){
        int i, al = strlen(str[rev^1]), bl = strlen(str[rev]);
        int mx = al>bl?al:bl, mi = al>bl?bl:al;
        for(i=0; i<mi; i++)
            if(str[rev^1][i] != str[rev][i])
                break;
        if(i != mi){
            char A = str[rev^1][i], B = str[rev][i];
            //printf("----%c %c--\n", A, B);
            if(!m[A]){
                m[A] = k;
                v[k].clear();
                pre[k] = 0;
                c[k++] = A;
            }
            if(!m[B]){
                m[B] = k;
                v[k].clear();
                pre[k] = 0;
                c[k++] = B;
            }
            pre[m[B]]++;
            v[m[A]].push_back(m[B]);
        }
        rev^=1;
    }
    if(k == 1)
        printf("%s", str[0]);
}
void sol(){
    for(int cnt = 1; cnt<k; cnt++){
        int now = -1;
        for(int i=1; i<k; i++)
            if(!pre[i]){
                now = i;
                break;
            }
        pre[now] = -1;
        for(int i=0; i<v[now].size(); i++)
            pre[v[now][i]]--;
        printf("%c", c[now]);
    }
    puts("");
}
int main(){
    init();
    sol();
    return 0;
}
