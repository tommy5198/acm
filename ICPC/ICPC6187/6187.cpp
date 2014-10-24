#include <cstdio>
using namespace std;
#define MAXN 100033
#define MAXLEN 10033
typedef long long int llint;

llint c[MAXN];
int r[MAXN];
int h[MAXN];

void f_s(int x){
    if(h[x]!=x){
        f_s(h[x]);
        c[x]=c[x]+c[ h[x] ];
        h[x]= h[ h[x] ];
    }
}

void u_s(int x,int y,llint trc){
    if(r[x]<r[y]){
        h[x]=y;
        c[x]=-trc;
    }
    else
    {
        h[y]=x;
        c[y]=trc;
        if(r[x]==r[y])r[x]++;
    }
}

int main()
{
    int n,m;
    int i,j;
    int u,v;
    int a,b;
    llint w,w1,w2;
    char input[MAXLEN];

    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0)break;
        for(i=1;i<=n;i++){
            c[i]=0LL;
            h[i]=i;
            r[i]=1;
        }
        while(m--){
            scanf("%s",input);
            if(input[0]=='!'){
                scanf("%d%d%lld",&a,&b,&w);
                if(a>b){
                    u=a;
                    a=b;
                    b=u;
                    w=-w;
                }
                f_s(a);
                f_s(b);
                u=h[a];
                v=h[b];
                w1=c[a];
                w2=c[b];
                u_s(u,v,w+w1-w2);
            }else if(input[0]=='?'){
                scanf("%d%d",&a,&b);
                f_s(a);
                f_s(b);
                u=h[a];
                v=h[b];
                if(u!=v){
                    puts("UNKNOWN");
                    continue;
                }else{
                    w1=c[a];
                    w2=c[b];
                    w=w2-w1;
                    printf("%lld\n",w);
                }
            }
        }
    }

    return 0;
}
