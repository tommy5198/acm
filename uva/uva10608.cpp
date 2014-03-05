#include<iostream>
#include<cstdio>
using namespace std;
int p[30001],r[30001],num[30001];

void init(int n){

    while(n--){
        p[n]=n;
        r[n]=0;
        num[n]=1;
    }
}

int FindSet(int x){
    if(x!=p[x])
        p[x]=FindSet(p[x]);
    return p[x];
}

void Link(int a,int b){
    if(r[a]>r[b]){
        p[b]=a;
        num[a]+=num[b];
    }else{
        p[a]=b;
        num[b]+=num[a];
        if(r[a]==r[b])
            r[b]++;
    }
}
void Union(int a,int b){

    int x=FindSet(a),y=FindSet(b);
    if(x!=y)
        Link(x,y);
}


int main(){

    int c;
    scanf("%d",&c);
        int n,m;
        while(c--){
            scanf("%d%d",&n,&m);
            init(n);
            int a,b;
            while(m--){
                scanf("%d%d",&a,&b);
                Union(a,b);
            }
            int M=0;
            for(int i=0;i<n;i++)
                if(num[i]>M)
                    M=num[i];
            printf("%d\n",M);
        }

    return 0;
}
