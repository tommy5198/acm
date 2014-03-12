#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int n, m, ans;
map<string, int> mp;
int p[5001], r[5001], num[5001];

bool init(){
    scanf("%d%d", &n, &m);
    if(!n && !m)
        return false;
    mp.clear();
    ans = 1;
    for(int i=1; i<=n; i++){
        string str;
        cin>>str;
        mp[str] = i;
        p[i] = i;
        r[i] = 0;
        num[i] = 1;
    }
    return true;
}

int findset(int x){
    return p[x]==x ? x : p[x]=findset(p[x]);
}

void uni(int a, int b){
    if(a == b)
        return ;
    else if(r[a] > r[b]){
        p[b] = a;
        num[a] += num[b];
        ans = ans>num[a] ? ans : num[a];
    }else{
        p[a] = b;
        num[b] += num[a];
        if(r[a] == r[b])
            r[b]++;
       ans = ans>num[b] ? ans : num[b];
    }
}

void sol(){
    for(int i=0; i<m; i++){
        string a, b;
        cin>>a>>b;
        uni(findset(mp[a]), findset(mp[b]));
    }
    printf("%d\n", ans);
}

int main(){

    while(init())
        sol();

    return 0;
}
