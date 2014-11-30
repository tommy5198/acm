#define INF 1000000
#define MAX 100
using namespace std;
typedef struct{
  int val,id;
}NODE;
typedef struct{
  int v,w;
}EDGE;
int dis[MAX];
bool find[MAX];
vector<EDGE>edg[MAX];
priority_queue<NODE>pque;
bool operator < (const NODE& a, const NODE& b){
  return a.val > b.val;
}
void dijkstra(int start,int n){
  int i,j,now;
  NODE tmp;
  for(i=0;i<n;++i)
  {
    dis[i]=INF;
    find[i]=false;
  }
  dis[start]=0;
  tmp.id=start;
  tmp.val=0;
  pque.push(tmp);
  for(i=0;i<n-1;++i)
  {
    if(pque.empty()) break;
    while(!pque.empty()&&find[pque.top().id]) pque.pop();
    if(pque.empty()) break;
    now=pque.top().id;
    pque.pop();
    find[now]=true;
    for(j=0;j<(int)edg[now].size();++j)
    {
      if(!find[edg[now][j].v])
      {
        if(dis[now]+edg[now][j].w<dis[edg[now][j].v])
        {
          dis[edg[now][j].v]=dis[now]+edg[now][j].w;
          tmp.id=edg[now][j].v;
          tmp.val=dis[edg[now][j].v];
          pque.push(tmp);
        }
      }
    }
  }
}
