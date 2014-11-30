#include<cstdio>
#include<cstring>
#define MAXN 16
#define INF 1e9
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

// Adj. Matrix
int edg[MAXN][MAXN];

// DP
int dp[1<<MAXN][MAXN];
bool used[1<<MAXN][MAXN];

// Initialize
void ini(void)
{
  int i,j;
  memset(used,false,sizeof(used));
}

// TSP
int TSP(int sts,int now,int n)
{
  int i,prev;

  // Basic - start at 0
  if(sts==1<<now)
    return edg[0][now];

  // Exist
  if(used[sts][now])
    return dp[sts][now];

  dp[sts][now]=INF;
  used[sts][now]=true;
  prev=sts-(1<<now);
  for(i=0;i<n;i++)
    if(prev&(1<<i))
      dp[sts][now]=min(dp[sts][now], \
              TSP(prev,i,n)+edg[i][now]);

  return dp[sts][now];
}

// Main
int main(void)
{
  int n,i,j;

  // Read Input
  while(scanf("%d",&n)==1)
  {
    if(!n)
    {
      printf("0\n");
      continue;
    }
    ini();
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",&edg[i][j]);
    printf("%d\n",TSP((1<<n)-1,0,n)); // 起點永遠是0
/* 若不需要回到0,
則ans=min(ans,TSP((1<<n)-1,i,n)),  i=0~n-1 */
  }
  return 0;
}
