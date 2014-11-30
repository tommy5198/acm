// 左邊跟右邊的最多node數
#define MAXL 102
#define MAXR 102
int link[MAXR];
bool used[MAXR];
vector<int>edg[MAXL];
bool DFS(int now)
{
  int i,next;
  for(i=0;i<(int)edg[now].size();++i)
  {
    next=edg[now][i];
    if(!used[next])
    {
      used[next]=true;
      if(!link[next]||DFS(link[next]))
      {
        link[next]=now;
        return true;
      }
    }
  }
  return false;
}
int Bipartite(int nL,int nR)
{
  int i,ans=0;
  memset(link,0,(nR+1)*sizeof(int));
  for(i=1;i<=nL;++i)
  {
    memset(used,false,(nR+1)*sizeof(bool));
    if(DFS(i)) ++ans;
  }
  return ans;
}
int main(void)
{
  int n,nL,nR,i,a,b;
  // n代表幾個pair，nL跟nR分別是左右set有幾個點
  while(scanf("%d%d%d",&n,&nL,&nR)==3)
  {
    // ID 1~nL/nR
    for(i=0;i<n;++i)
    {
      scanf("%d%d",&a,&b);
      edg[a].push_back(b);
    }
    printf("%d\n",Bipartite(nL,nR));
    for(i=1;i<=nL;++i) edg[i].clear();
  }
  return 0;	
}
