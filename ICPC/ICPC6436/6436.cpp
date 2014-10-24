#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 20033
typedef struct EDG
{
    int u,v;
    int nxt;
    EDG(int _u=0,int _v=0):u(_u),v(_v),nxt(-1){}
}EDG;
EDG edg[MAXN*2];
int edg_cnt;
int nxt[MAXN];
int ans[MAXN];
int cnt[MAXN];
int deg[MAXN];
bool vis[MAXN];
queue<int>q;
int max_ans;
int n;

void ini(){
    int i;
    for(i=1;i<=n;i++){
        nxt[i]=-1;
        ans[i]=0;
        cnt[i]=1;
        deg[i]=0;
        vis[i]=false;
    }
    edg_cnt=0;
    max_ans=0;
}

int main()
{
    int cas=1,casn;
    int a,b;
    int i,j;
    int u,v;

    scanf("%d",&casn);
    while(casn--){
        scanf("%d",&n);
        ini();
        for(i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            deg[a]++;
            deg[b]++;

            edg[edg_cnt]=EDG(a,b);
            edg[edg_cnt].nxt=nxt[a];
            nxt[a]=edg_cnt;
            edg_cnt++;
            edg[edg_cnt]=EDG(b,a);
            edg[edg_cnt].nxt=nxt[b];
            nxt[b]=edg_cnt;
            edg_cnt++;
        }
        /*
        for(i=1;i<=n;i++){
            printf("node %d:    %d\n",i,deg[i]);
        }
        */
        while(!q.empty())q.pop();

        for(i=1;i<n;i++){
            if(deg[i]==1)q.push(i);
        }
        while(!q.empty()){
            u=q.front();
            q.pop();
            vis[u]=true;
            
            ans[u]+=(cnt[u]-1)*(n-cnt[u]);
            for(j=nxt[u];j!=-1;j=edg[j].nxt){
                v=edg[j].v;
                if(vis[v])continue;
                ans[v]+=(cnt[u]*(cnt[v]-1));
                cnt[v]+=cnt[u];
                deg[v]--;
                if(deg[v]==1){
                    q.push(v);
                }
            }
        }
        for(i=1;i<=n;i++){
            if(max_ans<ans[i])max_ans=ans[i];
        }
        printf("Case #%d: %d\n",cas++,max_ans);
    }
    return 0;
}
