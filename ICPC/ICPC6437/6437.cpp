#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 203
typedef struct EDG
{
    int u,v,w;
    EDG(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
}EDG;

EDG edg[MAXN*MAXN];
int cnt;

int h[MAXN];
int r[MAXN];

int f_s(int x){
    if(x!=h[x])h[x]=f_s(h[x]);
    return h[x];
}
void u_s(int x,int y){
    if(r[x]<r[y]){
        h[x]=y;
    }else{
        h[y]=x;
        if(r[x]==r[y])r[x]++;
    }
}

int N,M,K;
int ans,ec;

bool cmp(EDG a,EDG b){
    return a.w<b.w;
}

void ini()
{
    int i;
    for(i=0;i<=N;i++){
        h[i]=i;
        r[i]=1;
    }
    cnt=0;
    ans=0;
    ec=0;
}

int main()
{
    int cas=1,casn;
    int i;
    int u,v,w,x,y;

    scanf("%d",&casn);
    while(casn--){
        scanf("%d%d%d",&N,&M,&K);
        ini();
        for(i=0;i<K;i++){
            scanf("%d",&u);
            edg[cnt++]=EDG(0,u,0);
        }
        for(i=0;i<M;i++){
            scanf("%d%d%d",&u,&v,&w);
            edg[cnt++]=EDG(u,v,w);
        }
        sort(edg,edg+cnt,cmp);
        for(i=0;i<cnt && ec<=N-1;i++){
            u=f_s(edg[i].u);
            v=f_s(edg[i].v);
            if(u!=v){
                u_s(u,v);
                ans+=edg[i].w;
                //printf ("edg %d %d %d\n",edg[i].u,edg[i].v,edg[i].w);
                ec++;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }

    return 0;
}
