#define MAXN 1033

int nx,ny,s[MAXN][MAXN];
int lowbit(int x){ return x&(-x); }

int getSum(int x, int y){
	int ret = 0;
	for( int i= x ; i>0 ; i-=lowbit(i) )
		for( int j=y ; j>0 ; j-=lowbit(j) )
			ans+=s[i][j];
	return ans;
}
int add(int x,int y,int d){
	for( int i=x ; i<nx ; i+=low_bit(i) )
		for( int j=y ; j<ny ; j+=low_bit(j) )
			s[i][j]+=d;
}
