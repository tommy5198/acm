typedef struct node{
  int next,w;
}EDGE;
int count[VMAX],dis[VMAX]; //VMAX點個數
bool inqueue[VMAX];
queue<int>que;
vector<EDGE>edge[VMAX];
bool SPFA(int start,int n){
  int i,now,next;
  for(i=0;i<n;++i){
    count[i]=0;
    dis[i]=INF;
    inqueue[i]=false;
  }
  que.push(start);
  dis[start]=0;
  count[start]=1;
  while(!que.empty())
  {
    now=que.front();
    que.pop();
    inqueue[now]=false;
    for(i=0;i<(int)edge[now].size();++i)
    {
      next=edge[now][i].next;
      if(dis[next]>dis[now]+edge[now][i].w)
      {
        dis[next]=dis[now]+edge[now][i].w;
        if(!inqueue[next])
        {
          que.push(next);
          inqueue[next]=true;
          count[next]++;
        }
        if(count[next]>=n)return true;
      }
    }
  }
  return false;
}
