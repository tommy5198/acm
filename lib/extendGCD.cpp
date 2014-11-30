// ax + by = gcd, |x|+|y| will be minimum
void exgcd(int a,int b,int &x,int &y, int &gcd){
	if(b==0)
		gcd=a,x=1,y=0;
	else{
		exgcd(b, a%b, y, x , gcd);
		y = y - (a/b) * x;
	}
}
