// 加單向邊 addEdge(u,v,cost,capacity);
// 初始化 tot=0; memset(prev,-1,sizeof(prev));
#define MAXE 10010		// 邊個數
#define MAXN 102		// 點個數
#define min(a,b) ((a)<(b)?(a):(b))
#define INF (int)1e9
using namespace std;

typedef struct{
  int u,v,next;
  int flow,cost;
}EDGE;

int prev[MAXN],p[MAXN],tot,que[MAXN],dis[MAXN];
bool inque[MAXN];
EDGE edg[MAXE*2];

void add(int u,int v,int cost,int flow){
  edg[tot].u=u;
  edg[tot].v=v;
  edg[tot].flow=flow;
  edg[tot].cost=cost;
  edg[tot].next=prev[u];
  prev[u]=tot++;
}

void addEdge(int u,int v,int cost,int flow){
  add(u,v,cost,flow);
  add(v,u,-cost,0);
}

bool spfa(int s,int t,int n){
  int i,head,tail,now,next;
  for(i=0;i<n;++i)
  {
    dis[i]=INF;
    inque[i]=false;
    p[i]=-1;
  }
  dis[s]=0;
  head=tail=0;
  que[tail++]=s;
  inque[s]=true;
  while(head<tail)
  {
    now=que[head%MAXN];
    inque[now]=false;
    ++head;
    for(i=prev[now];i!=-1;i=edg[i].next)
    {
      next=edg[i].v;
      if(edg[i].flow&&dis[now]+edg[i].cost<dis[next])
      {
        dis[next]=dis[now]+edg[i].cost;
        p[next]=i;
        if(!inque[next])
        {
          que[tail%MAXN]=next;
          inque[next]=true;
          ++tail;
        }
      }
    }
  }
  return dis[t]!=INF;
}

void MCMF(int s,int t,int n)
{
  int i,MF=0,mc=0,ff;

  while(spfa(s,t,n)){
    ff=INF;
    for(i=p[t];i!=-1;i=p[edg[i].u])
      ff=min(ff,edg[i].flow);

    for(i=p[t];i!=-1;i=p[edg[i].u]){
      edg[i].flow-=ff;
      edg[i^1].flow+=ff;
    }

    MF+=ff;
    mc+=ff*dis[t];
  }
  // MF -> MaxFlow
  // mc -> minimum cost
}
