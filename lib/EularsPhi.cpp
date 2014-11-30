#define MAXN 2000001
int euler[MAXN];
bool isprim[MAXN];
void phi(int n){
  memset(isprim,true,(n+1)*sizeof(bool));
  for(int i=1;i<=n;++i) euler[i]=i;
  isprim[0]=isprim[1]=false;
  for(int i=2;i<=n;++i){
    if(isprim[i]){
      euler[i]=i-1;
      for(j=i+i;j<=n;j+=i){
        isprim[j]=false;
        euler[j]-=euler[j]/i;
      }
    }
  }
}
