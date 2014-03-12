#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int n, ans, k = 1;
map<string, int> m;
int p[200002], r[200002], num[200002];

void init(){
    scanf("%d", &n);
    k = 1;
    m.clear();
}

int findset(int x){
    return p[x]==x ? x : p[x]=findset(p[x]);
}

void uni(int a, int b){
    if(a == b){
        ans = num[a];
        return ;
    }
    if(r[a] > r[b]){
        p[b] = a;
        num[a] += num[b];
        ans = num[a];
    }else{
        p[a] = b;
        num[b] += num[a];
        if(r[a] == r[b])
            r[b]++;
        ans = num[b];
    }
}

int main(){
    int T;
    scanf("%d", &T);
    //freopen("t.out", "w", stdout);
    while(T--){
        init();
        for(int i=0; i<n; i++){
            string str[2];
            cin>>str[0]>>str[1];
            if(!m[str[0]]){
                p[k] = k;
                r[k] = 0;
                num[k] = 1;
                m[str[0]] = k++;
            }
            if(!m[str[1]]){
                p[k] = k;
                r[k] = 0;
                num[k] = 1;
                m[str[1]] = k++;
            }
            uni(findset(m[str[0]]), findset(m[str[1]]));
            printf("%d\n", ans);
        }
    }
    return 0;
}
