// Minimum Enclosing Circle avg:O(N) worst:O(N^2)
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

struct Point{
	double x, y;
};
struct Line{
	double a, b, c;
};

int n;
Point p[100];
Point center;
const double eps = 1e-6;

double dis(Point a, Point b) {
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
Line getl(Point p1, Point p2, Line &l) {
	l.a=p2.x-p1.x;
	l.b=p2.y-p1.y;
	l.c=0.0-(l.a*(p1.x+p2.x)/2.0+l.b*(p1.y+p2.y)/2.0);
}

Point getp(Line l1, Line l2, Point &pot) {
	double bse;
	bse=l1.a*l2.b-l1.b*l2.a;
	pot.x=(l2.c*l1.b-l2.b*l1.c)/bse;
	pot.y=(l1.c*l2.a-l1.a*l2.c)/bse;
}
/*
Point findCenter(Point a, Point b, Point c) {
	return getp(getl(a, b), getl(b, c));
}

double threePoint(Point a, Point b, Point c) {
	return dis(findCenter(a, b, c), a);
}
*/
double threePoint(Point P1, Point P2, Point P3)

{
	Line L1, L2;
	getl(P1,P2,L1);

	getl(P2,P3,L2);

	getp(L1,L2,center);

	return dis(center,P1);

}
double twoPoint(Point a, Point b, int idx) {
	double r = dis(a, b) / 2.;
	center.x = (a.x+b.x) / 2.;
	center.y = (a.y+b.y) / 2.;
	for(int i=0; i<idx; i++)
		if(dis(center, p[i]) > r)
			r = threePoint(a, b, p[i]);
	return r;
}

double onePoint(Point a, int idx) {
	double r = dis(p[0], a) / 2.;
	center.x = (a.x+p[0].x) / 2.;
	center.y = (a.y+p[0].y) / 2.;
	for(int i=1; i<idx; i++)
		if( dis(center, p[i]) > r)
			r = twoPoint(a, p[i], i);
	return r;
}

double findCircle() {
	double r = dis(p[0], p[1]) / 2.;
	center.x = (p[1].x+p[0].x) / 2.;
	center.y = (p[1].y+p[0].y) / 2.;
	for(int i=2; i<n; i++)
		if( dis(center, p[i]) > r)
			r = onePoint(p[i], i);
	return r;
}

int main() {
	while(scanf("%d", &n), n) {
		for(int i=0; i<n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		double R;
		scanf("%lf", &R);
		/*
		if(n == 1 && R - eps > 0 || n > 1 && R - findCircle() > eps)
			puts("The polygon can be packed in the circle.");
		else
			puts("There is no way of packing that polygon.");
			*/
		if(n==1 & R>0-eps)
			printf("The polygon can be packed in the circle.\n");
		else if(fabs(R-0.0) < eps)
			printf("There is no way of packing that polygon.\n");
		else if(findCircle() -eps<R)
			printf("The polygon can be packed in the circle.\n");
		else
			printf("There is no way of packing that polygon.\n");
		//printf("%lf\n", r);
	}
	return 0;
}

