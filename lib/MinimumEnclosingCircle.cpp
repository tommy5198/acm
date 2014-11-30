#include<cstdio>
#include<cmath>
#define dis(a,b) sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
#define MAXN 102
using namespace std;

// (x,y)
typedef struct{
  double x,y;
}POINT;
typedef struct{      // ax+by+c=0
  double a,b,c;
}LINE;

// Circle
typedef struct{
  double r;
  POINT cen;
}CIRCLE;

// Find ax+by+c=0
LINE getL(POINT p1, POINT p2)
{
  LINE l;
  l.a=p2.y-p1.y;
  l.b=p1.x-p2.x;
  l.c=(p2.x-p1.x)*p1.y+(p1.y-p2.y)*p1.x;
  return l;
}

// Find Mid Vertical Line
LINE getMVL(POINT p1, POINT p2)
{
  LINE l,org;
  org=getL(p1,p2);
  l.a=org.b;
  l.b=-org.a;
  l.c=(-l.a)*(p1.x+p2.x)/2+(-l.b)*(p1.y+p2.y)/2;
  return l;
}

// Find Intersect
POINT getP(LINE l1,LINE l2)
{
  double bse,dx,dy;
  POINT p;
  bse=l1.a*l2.b-l2.a*l1.b;
  dx=(-l1.c)*l2.b-(-l2.c)*l1.b;
  dy=l1.a*(-l2.c)-l2.a*(-l1.c);
  p.x=dx/bse;
  p.y=dy/bse;
  return p;
}

// Find Circle
CIRCLE getCIRCLE(POINT p1,POINT p2,POINT p3)
{
  LINE l1,l2;
  CIRCLE c;
  l1=getMVL(p1,p2);
  l2=getMVL(p2,p3);
  c.cen=getP(l1,l2);
  c.r=sqrt( (p1.x-c.cen.x)*(p1.x-c.cen.x) \
           +(p1.y-c.cen.y)*(p1.y-c.cen.y) \
          );
  return c;
}

// n points
POINT pt[MAXN];

// check the third point
void third_check(CIRCLE &c,int id,int id2)
{
  int i;
  c.r=dis(pt[id],pt[id2])/2;
  c.cen.x=(pt[id].x+pt[id2].x)/2;
  c.cen.y=(pt[id].y+pt[id2].y)/2;

  // check the points between two points
  for(i=0;i<id;i++)
    if(dis(c.cen,pt[i])>c.r)
      c=getCIRCLE(pt[id],pt[id2],pt[i]);
}

// check the second point
void second_check(CIRCLE &c,int id)
{
  int i;
  c.r=dis(pt[0],pt[id])/2;
  c.cen.x=(pt[0].x+pt[id].x)/2;
  c.cen.y=(pt[0].y+pt[id].y)/2;

  // check the points between two points
  for(i=1;i<id;i++)
    if(dis(c.cen,pt[i])>c.r)
      third_check(c,i,id);
}

// find the minimum radius of n points
void min_enclosing_circle(CIRCLE &c,int n)
{
  int i;

  // only one point
  if(n==1)
  {
    c.cen=pt[0];
    c.r=0.0;
    return;
  }

  // radius for two points
  c.cen.x=(pt[0].x+pt[1].x)/2;
  c.cen.y=(pt[0].y+pt[1].y)/2;
  c.r=dis(pt[0],pt[1])/2;
  if(n==2) return;

  // check the third point
  for(i=2;i<n;i++)
    if(dis(c.cen,pt[i])>c.r)
      second_check(c,i);
}

int main(void)
{
  int i,n;
  CIRCLE c;

  while(scanf("%d",&n)==1)
  {
    // Read n points
    for(i=0;i<n;i++)
      scanf("%lf%lf",&pt[i].x,&pt[i].y);

    // Find the radius enclosing all points
    min_enclosing_circle(c,n);
    printf("%lf %lf %lf\n",c.cen.x,c.cen.y,c.r);
  }

  return 0;
}
