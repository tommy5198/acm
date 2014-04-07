#include<cstdio>

struct node{
    char c[2];
    bool operator==(const node &t)const{
        if(c[0]==t.c[0] && c[1]==t.c[1])
            return true;
        return false;
    }
    bool operator<(const node &t)const{
        if(c[0]==t.c[0])
            return c[1]<t.c[1];
        return c[0]<t.c[0];
    }
}v[26*26];

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    char str[1001];
    for(int i=0; i<n; i++){
        int l, num=0;
        char c, pre = 0, ppre;
        for(l=0; c=getchar(); l++){
            if(l == 1)
                e[m].u = (c-'a')*26+pre-'a';
            ppre = pre;
            pre = c;
        }
        if(l==2)
            e[m].v = e[m].u;
        else
            e[m].v = (ppre-'a')*26+pre-'a';

    }
    return true;
}
