#include<cstdio>
#include<cmath>

int gcd(int a, int b)
{
	return a%b ? gcd(b, a%b):b;
}


int main()
{
	while(scanf("%d", &N), N) {
		for(int i=0; i<N; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
			E += i ? gcd(abs(a.x-b.x), abs(a.y,b.y)) : N;
			for(
	}
	return 0;
}
