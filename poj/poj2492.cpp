//disjoint set rewrite by uva10158
#include<cstdio>

int n, m;
int p[2002];
bool s[2002];

void init(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        p[i] = i;
        s[i] = false;
    }
}

int findset(int x){
    bool sex = false;
    int pt = x;
    while(p[pt] != pt){
        sex ^= s[pt];
        pt = p[pt];
    }
    s[x] = sex;
    return p[x] = pt;
}

bool sol(){
    bool found = false;
    for(int i=0; i<m; i++){
        int a, b, ta, tb;
        scanf("%d%d", &a, &b);
        if(found) continue;
        ta = findset(a);
        tb = findset(b);
        if(ta == tb)
            found = s[a] == s[b];
        else{
            p[ta] = tb;
            s[ta] = s[a]==s[b];
        }
    }
    return found;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        init();
        printf("Scenario #%d:\n", i);
        if(sol())
            puts("Suspicious bugs found!");
        else
            puts("No suspicious bugs found!");
        if(i != T)
            puts("");
    }
    return 0;
}
