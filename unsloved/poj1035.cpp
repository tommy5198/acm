#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct Word{
    char c[16];
    bool operator<(const Word &t)const{
        int l = strlen(c), tl = strlen(t.c);
        if(l != tl)
            return l < tl;
        for(int i=0; i<l; i++)
            if(c[i] != t.c[i])
                return c[i] < t.c[i];
        return true;
    }
};

int main(){
    Word tmp;
    map<Word, int> m;
    vector<Word> v;
    vector<int> ans;
    int cnt = 1;
    while(scanf("%s", tmp.c), tmp.c[0] != '#'){
        m[tmp] = cnt++;
        v.push_back(tmp);
    }
    while(scanf("%s", tmp.c), tmp.c[0] != '#'){
        if(m[tmp]){
            printf("%s is correct\n", tmp.c);
            continue;
        }
        printf("%s:", tmp.c);
        int len = strlen(tmp.c);
        for(int i = 0; i<len; i++){
            char ori = tmp.c[i];
            for(char rep = 'a'; rep<='z'; rep++){
                tmp.c[i] = rep;
                if(m[tmp])
                    ans.push_back(m[tmp]);
            }
            tmp.c[i] = ori;
        }
        if(len != 15){
            for(int i=0; i<=len; i++){
                Word TMP;
                for(int j = 0, k = 0; j<=len; j++, k++){
                    if(i == j){
                        continue; k--;
                    }else
                        TMP.c[j] = tmp.c[k];
                }
                for(char ad = 'a'; ad<='z'; ad++){
                    TMP.c[i] = ad;
                    if(m[TMP])
                        ans.push_back(m[TMP]);
                }
            }
        }else if(len != 1){
            for(int i=0; i<len; i++){
                Word TMP;
                for(int j = 0, k = 0; j<len; j++, k++){
                    if(i == j){
                        continue; k--;
                    }else
                        TMP.c[k] = tmp.c[j];
                }
                for(char ad = 'a'; ad<='z'; ad++)
                    if(m[TMP])
                        ans.push_back(m[TMP]);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size();i++)
            printf(" %s", v[ans[i]]);
        printf("\n");
    }
    return 0;
}
