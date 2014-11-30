// D_type 改成Flow 的Type
#include<cstdio>
#include<cstring>
#define VTEX 100
#define MAXE 100000
#define INF 10000000
#define min(a,b) ((a)<(b)?(a):(b))
#define rev(x) (x&1?(x-1):(x+1))
typedef int D_type;
using namespace std;
typedef struct{
  int v,next;
  D_type flow;
}EDGE;
int pre[VTEX],level[VTEX],que[VTEX];
EDGE edg[MAXE];
bool build(int source,int sink)
{
  int i,head=0,tail=0,now;
  memset(level,0,(sink+1)*sizeof(int));
  level[source]=1;
  que[tail++]=source;
  while(head<tail)
  {
    now=que[head%VTEX];
    ++head;
    for(i=pre[now];i!=-1;i=edg[i].next)
    {
      if(edg[i].flow&&!level[edg[i].v])
      {
        que[tail%VTEX]=edg[i].v;
        ++tail;
        level[edg[i].v]=level[now]+1;
        if(edg[i].v==sink) return true;
      }
    }
  }
  return false;
}
D_type findflow(int now,D_type beforemin,int sink)
{
  int i;
  D_type ans=0,flow;
  if(now==sink||!beforemin) return beforemin;
  for(i=pre[now];i!=-1;i=edg[i].next)
  {
    if(level[edg[i].v]==level[now]+1&& \
      (flow=findflow(edg[i].v,min(beforemin,edg[i].flow),sink)))
    {
      edg[i].flow-=flow;
      edg[rev(i)].flow+=flow;
      ans+=flow;
      beforemin-=flow;
      if(beforemin==0) break;
    }
  }
  return ans;
}
D_type dinic(int source,int sink)
{
  D_type ans=0;
  while(build(source,sink)) ans+=findflow(source,INF,sink);
  return ans;
}
int main(void)
{
  int i,n,m,index,a,b;
  D_type w;
  scanf("%d%d",&n,&m);
  memset(pre,-1,n*sizeof(int));
  for(i=index=0;i<m;++i)
  {
    scanf("%d%d%d",&a,&b,&w);
    edg[index].v=b;
    edg[index].flow=w;
    edg[index].next=pre[a];
    pre[a]=index++;
    edg[index].v=a;
    edg[index].flow=0;
    edg[index].next=pre[b];
    pre[b]=index++;
  }
  printf("%d\n",dinic(0,n-1));
  return 0;
}
