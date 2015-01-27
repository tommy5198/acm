#include<cstdio>
#include<cmath>

struct Point {
    double x, y;
} p[1000];

double gcd(int a, int b)
{
    if(!b) return a;
	return a%b ? gcd(b, a%b) : b;
}

double Area(Point a, Point b) {
    return (a.x*b.y - a.y*b.x) / 2.;
}

int main()
{
    int N;
	while(scanf("%d", &N), N) {
        double A = 0, E = 0;
		for(int i=0; i<N; i++) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
			if(i) {
                E += gcd(fabs(p[i].x-p[i-1].x), fabs(p[i].y-p[i-1].y));
                A += Area(p[i-1], p[i]);
                //printf("%lf %lf\n", E, A);
			}
		}
		E += gcd(fabs(p[0].x-p[N-1].x), fabs(p[0].y-p[N-1].y));
		A += Area(p[N-1], p[0]);
		A = A < 0 ? -A : A;
		printf("%.0lf\n", A - E/2 + 1);
	}
	return 0;
}
