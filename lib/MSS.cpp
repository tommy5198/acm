// 若整個ary都是負的，輸出最大的entry就好
#define HM 30  //1D
#define RM 30  //2D
#define CM 30  //3D
int MSS1D(int n , int ary[]){
  int i , sum , M;
  M = sum = 0;
  for(i = 0 ; i<n ; ++i )
  {
    sum += ary[i];
    if(sum < 0 )	sum = 0;
    if(sum > M )	M = sum;
  }
  return M;
}
int MSS2D(int R,int C,int ary[RM][CM])
{
  int left,width,sum,M,i,tmp[RM];
  M=0;
  for(left=0;left<C;++left)
  {
    for(i=0;i<R;++i) tmp[i]=0;
    for(width=0;width+left<C;++width)
    {
      for(i=0;i<R;++i) tmp[i]+=ary[i][left+width];
      sum=MSS1D(R,tmp);
      if(sum>M) M=sum;
    }
  }
  return M;
}
int MSS3D(int H,int R,int C,int ary[HM][RM][CM])
{
  int start,width,sum,M,i,j,tmp[RM][CM];
  M=0;
  for(start=0;start<H;++start)
  {
    for(i=0;i<R;++i)
      for(j=0;j<C;++j)
        tmp[i][j]=0;
    for(width=0;width+start<H;++width)
    {
      for(i=0;i<R;++i)
        for(j=0;j<C;++j)
          tmp[i][j]+=ary[width+start][i][j];
      sum=MSS2D(R,C,tmp);
      if(sum>M) M=sum;
    }
  }
  return M;
}
