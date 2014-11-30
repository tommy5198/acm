int bellman(int n,int edg)
{
  int i,j,flag;
  for(i=1;i<=n;++i) dis[i]=INF;
  dis[1]=0;
  for(i=0;i<n-1;++i){
    for(j=flag=0;j<edg;++j){
      if(dis[edge[j].u]+edge[j].w<dis[edge[j].v])
dis[edge[j].v]=dis[edge[j].u]+edge[j].w;
      flag=1;
    }
    if(!flag) return 1; //沒有negative cycle
  }
  for(j=0;j<edg;++j) //檢查negative cycle
      if(dis[edge[j].u]+edge[j].w<dis[edge[j].v]) return 0;
  return 1; //沒有negative cycle
}
