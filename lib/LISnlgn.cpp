#define MAXN 100
using namespace std;
int pos[MAXN],lis[MAXN],seq[MAXN],ans[MAXN];
int main(void)
{
  int i,n,len,l,r,mid,now;
  while(scanf("%d",&n)!=EOF)
  {
    for(i=0;i<n;i++) scanf("%d",&seq[i]);

    // 初始化
    len=0;
    lis[len++]=seq[0];
    pos[0]=1;

    // 嚴格遞增
    for(i=1;i<n;i++)
    {
      // Append
      if(lis[len-1]<seq[i]) // 若是非遞減: 改成<=
      {
        lis[len++]=seq[i];
        pos[i]=len;
      }
      else
      {
        // Binary Search
        l=0,r=len-1;
        while(l<r)
        {
          mid=l+(r-l)/2;
          if(lis[mid]<seq[i]) l=mid+1; //非遞減: 改成<=
          else r=mid;
        }

        //選擇正確的地方插入
        lis[r]=seq[i];
        pos[i]=r+1;
      }
    }

    // LIS答案
    printf("%d\n",len);

    //其中一組解
    for(i=n-1,now=len;i>=0&&now>0;i--)
      if(pos[i]==now)
        ans[--now]=seq[i];
    for(i=0;i<len;i++) printf(" %d",ans[i]);
    printf("\n");
  }
  return 0;
}
