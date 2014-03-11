//topsort
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, k;
struct ANS{
    char a[27];
    bool operator<(const ANS &t)const{
        for(int i=0; i<k; i++)
            if(a[i] != t.a[i])
                return a[i] < t.a[i];
        return true;
    }
}tmp;
vector<ANS> Ans;
int cha[26][2][2];
char pic[31][31];
char ans[26];
bool v[26][26];
bool exist[26];
int pre[26];
void input(){
    char c;
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            c = getchar();
            pic[i][j] = c;
            if(c != '.'){
                if(!exist[c - 'A']) k++;
                exist[c-'A'] = true;
                cha[c - 'A'][0][0] = min(cha[c - 'A'][0][0], i);
                cha[c - 'A'][0][1] = min(cha[c - 'A'][0][1], j);
                cha[c - 'A'][1][0] = max(cha[c - 'A'][1][0], i);
                cha[c - 'A'][1][1] = max(cha[c - 'A'][1][1], j);
            }
        }
        getchar();
        //puts("");
    }
}
bool colli(char a, int x, int y){
    if(a == pic[x][y]) return false;
    int tmp[2] = {x, y};
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            if(cha[a-'A'][i][j] == tmp[j])
            if(cha[a-'A'][0][j^1] <= tmp[j^1] && cha[a-'A'][1][j^1] >= tmp[j^1])
                return true;
    return false;
}
void check(){
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        if(pic[i][j] != '.')
            for(int idx = 0; idx<26; idx++)
                if(exist[idx] && !v[ pic[i][j] - 'A' ][idx] && colli(idx+'A', i, j)){
                    pre[idx]++;
                    v[ pic[i][j] - 'A' ][idx] = true;
                }
}
void sol(int cnt){
    if(cnt == -1){
        //print
        Ans.push_back(tmp);
        return ;
    }
    for(int i=0; i<k; i++)
        if(exist[i] && !pre[i]){
            tmp.a[cnt] = i + 'A';
            pre[i] = -1;
            for(int j=0; j<26; j++)
                if(v[i][j])
                    pre[j]--;
            sol(cnt-1);
            pre[i] = 0;
            for(int j=0; j<26; j++)
                if(v[i][j])
                    pre[j]++;
        }
}
void init(){
    k = 0;
    Ans.clear();
    for(int i=0; i<26; i++){
        pre[i] = 0;
        exist[i] = false;
        cha[i][0][0] = 10000;
        cha[i][0][1] = 10000;
        cha[i][1][0] = -1;
        cha[i][1][1] = -1;
        for(int j=0; j<26; j++)
            v[i][j] = false;
    }
}
int main(){
    //freopen("t.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        input();
        check();
        tmp.a[k] = 0;
        sol(k-1);
        sort(Ans.begin(), Ans.end());
        for(int i=0; i<Ans.size(); i++)
            puts(Ans[i].a);
    }
    return 0;
}#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, k;
struct ANS{
    char a[27];
    bool operator<(const ANS &t)const{
        for(int i=0; i<k; i++)
            if(a[i] != t.a[i])
                return a[i] < t.a[i];
        return true;
    }
}tmp;
vector<ANS> Ans;
int cha[26][2][2];
char pic[31][31];
char ans[26];
bool v[26][26];
bool exist[26];
int pre[26];
void input(){
    char c;
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            c = getchar();
            pic[i][j] = c;
            if(c != '.'){
                if(!exist[c - 'A']) k++;
                exist[c-'A'] = true;
                cha[c - 'A'][0][0] = min(cha[c - 'A'][0][0], i);
                cha[c - 'A'][0][1] = min(cha[c - 'A'][0][1], j);
                cha[c - 'A'][1][0] = max(cha[c - 'A'][1][0], i);
                cha[c - 'A'][1][1] = max(cha[c - 'A'][1][1], j);
            }
        }
        getchar();
        //puts("");
    }
}
bool colli(char a, int x, int y){
    if(a == pic[x][y]) return false;
    int tmp[2] = {x, y};
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            if(cha[a-'A'][i][j] == tmp[j])
            if(cha[a-'A'][0][j^1] <= tmp[j^1] && cha[a-'A'][1][j^1] >= tmp[j^1])
                return true;
    return false;
}
void check(){
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        if(pic[i][j] != '.')
            for(int idx = 0; idx<26; idx++)
                if(exist[idx] && !v[ pic[i][j] - 'A' ][idx] && colli(idx+'A', i, j)){
                    pre[idx]++;
                    v[ pic[i][j] - 'A' ][idx] = true;
                }
}
void sol(int cnt){
    if(cnt == -1){
        //print
        Ans.push_back(tmp);
        return ;
    }
    for(int i=0; i<k; i++)
        if(exist[i] && !pre[i]){
            tmp.a[cnt] = i + 'A';
            pre[i] = -1;
            for(int j=0; j<26; j++)
                if(v[i][j])
                    pre[j]--;
            sol(cnt-1);
            pre[i] = 0;
            for(int j=0; j<26; j++)
                if(v[i][j])
                    pre[j]++;
        }
}
void init(){
    k = 0;
    Ans.clear();
    for(int i=0; i<26; i++){
        pre[i] = 0;
        exist[i] = false;
        cha[i][0][0] = 10000;
        cha[i][0][1] = 10000;
        cha[i][1][0] = -1;
        cha[i][1][1] = -1;
        for(int j=0; j<26; j++)
            v[i][j] = false;
    }
}
int main(){
    //freopen("t.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        input();
        check();
        tmp.a[k] = 0;
        sol(k-1);
        sort(Ans.begin(), Ans.end());
        for(int i=0; i<Ans.size(); i++)
            puts(Ans[i].a);
    }
    return 0;
}

