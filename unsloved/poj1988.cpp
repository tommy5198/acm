//disjoint set
#include<cstdio>

int p[30001], r[30001], num[30001];

void init(){
    for(int i=1; i<=30000; i++){
        p[i] = i;
        r[i] = 0;
        num[i] = 1;
    }
}

int fd(int x){
    int px = x;
    while(p[px] != px){


        px = p[px];
    }
}

void uni(int ta, int tb){
    int a = fd(ta), b = fd(tb);
    p[b] = a;
    r[b] =
    num[a] += num[b];

}
