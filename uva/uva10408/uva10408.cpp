#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define eps 1e-6

double gcd(int a, int b)
{
	return a%b ? gcd(b, a%b) : b;
}

int main() {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		int px, py, x = 0, y = 1, nx = 1, ny = n;
		for(int i=1; i<k; i++) {
			int k = (n+y) / ny;
			px = x;
			py = y;
			x = nx;
			y = ny;
			nx = k*x - px;
			ny = k*y - py;
		}
		printf("%d/%d\n", nx, ny);
	}
	return 0;
}

