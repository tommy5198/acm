#define eps 1e-7
#define MAXPN 1003
#define MAXLN 1003
int dcmp(double x){
if(fabs(x)<eps)return 0;
  else return x<0? -1:1;
}

typedef struct Point{
  double x,y;
  Point(double x=0,double y=0):x(x),y(y){}
  Point operator/(double r)const{ return Point(x/r , y/r); }

  double operator*(const Point &p)const{  // 內積
  return x*p.x + y*p.y;
  }
  double operator^(const Point &p)const{  // 外積
    return x*p.y - y*p.x;
  }

  bool operator< (const Point &p)const{  // 小於
    return dcmp(x-p.x)< 0 ||
(dcmp(x-p.x)==0 && dcmp(y-p.y) < 0);
  }

    double len() { return sqrt(x*x+y*y); }   // 長度
    double len2(){ return x*x+y*y; }
    double angle(){ return atan2(y,x); }     // 向量極角
}Point;
typedef Point Vector;

Vector rot(Vector v,double a){      // 向量逆時針旋轉a
    return Vector(	v.x * cos(a)	- v.y * sin(a),
               	v.x * sin(a)	+ v.y * cos(a));
}

typedef struct Line_f{            // ax+by+c=0
    double a,b,c;
    Line_f(double a=0,double b=0,double c=0):
a(a),b(b),c(c){}
    Line_f(Point A,Point B){
        a =    A.y - B.y;
        b =  - (A.x - B.x);
        c = - a*A.x - b*A.y;
    }
}Line_f;

int get_inter_point(L_f L1, L_f L2, Pt &ret){ //兩直線交點
    double delta_x=(L2.c*L1.b-L2.b*L1.c); // 1: 交一點
    double delta_y=(L1.c*L2.a-L1.a*L2.c); // 0: 平行

  if(dcmp(delta)==0){
    if(dcmp(delta_x)==0 && dcmp(delta_y)==0)return 2;
    else                                  return 0;
  }
    ret = Point(delta_x/delta , delta_y/delta);
    return 1;
}   // return 2:same line,   1:point,   0:parallel

int ori(Point A,Point B,Point C){  // △ABC有向面積正負
    return dcmp( (B-A) ^ (C-A) );
}
double area(Point p[],int n){   // 多邊形有向面積
    double ret=0.0;
    for(int i=0;i<n;i++) ret += p[i] ^ p[(i+1)%n ];
    return ret/2.0;
}

bool btw(Point tar, Point B, Point C){  // A是否在BC之間
    return dcmp( (B-tar)*(C-tar) ) < 0;  // eg: B A C
}

//tar是否在BC線段上(不含端點)
bool isPointOnSegment(Pt tar, Pt B,Pt C){
    return dcmp((B-tar)^(C-tar))==0 && 
dcmp((B-tar)*(C-tar))<0;
}
//tar是否在多邊形內
int isPointInPolygon(Point tar, Point p[], int pn){
  int wn = 0;
  for(int i=0;i<pn;i++){
    if(isPointOnSegment(tar,p[i],p[(i+1)%pn]))return -1;
if( tar == p[i] || tar == p[(i+1)%pn] )return -1;
    int k = dcmp((p[(i+1)%pn]-p[i])^(tar-p[i]));
    int d1= dcmp(p[i].y        - tar.y);
    int d2= dcmp(p[(i+1)%pn].y - tar.y);
    if(k>0 && d1 <= 0 && d2 > 0) wn++;
    if(k<0 && d2 <= 0 && d1 > 0) wn--;
    }
    if(wn!=0)return 1;  // 在內部
    else     return 0;  // 在外部
}
// tar是否在凸多邊形內
int isPointInConvex(Point tar,Point p[],int pn){
for(int i=0;i<pn;i++){
if(isPointOnSegment(tar,p[i],p[(i+1)%pn]))return -1; 
if( tar == p[i] || tar == p[(i+1)%pn] )return -1;
// 逆時針不再左側或線段上
if(dcmp((p[i]-tar)^(p[(i+1)%pn]-tar))<=0)return 0;
}
return 1;
}
// tar是否在凸多邊形內、上
int isPointInConvex_NlogN(Point tar,Point p[],int n){
if(n<3)return 0;
if( dcmp((tar-p[0])^(p[  1]-p[0]))>0 )return 0;
if( dcmp((tar-p[0])^(p[n-1]-p[0]))<0 )return 0;
int L=2,R=n-1,M,line=-1;
while(L<=R){
M=(L+R)/2;
if( dcmp( (tar-p[0])^(p[M]-p[0]) )>=0 )line=M, R=M-1;
else L=M+1;
}
return dcmp( (p[line]-p[line-1])^(tar-p[line-1]) )>=0;
}

bool segmentIntersection(Pt p1, Pt p2, Pt p3, Pt p4){
    int a123 = ori(p1,p2,p3);     /* 線段是否相交 */
    int a124 = ori(p1,p2,p4);     // 含端點
    int a341 = ori(p3,p4,p1);
    int a342 = ori(p3,p4,p2);
    if(a123 == 0 && a124 ==0){  // 共線
        return btw(p1,p3,p4) || btw(p2,p3,p4) || btw(p3,p1,p2) || btw(p4,p1,p2);
    }else if(a123*a124<=0 && a341*a342<=0)return true;
    return false;
}

/* 如果不希望在凸包的邊上有輸入點， 把 <= 改成 < */
void getConvexHull(Point p[], int pn, Point ch[], int &m){
    sort(p,p+pn);
    m=0;
for(int i=0;i<pn;i++){
while(m>1 && dcmp((ch[m-1]-ch[m-2])^(p[i]-ch[m-2]))<=0)m--;
        ch[m++] = p[i];
    }
    int k=m;
    for(int i=pn-2;i>=0;i--){
        while(m>k && dcmp( (ch[m-1]-ch[m-2])^(p[i]-ch[m-2]) )<=0)m--;
        ch[m++] = p[i];
    }
    if(pn>1)m--;
}

/* 有向直線，左邊為對應半平面 */
typedef struct Line{
    Point  p;       // 直線上任一點
    Vector v;       // 方向向量
    double angle;   // 極角

    Line(Point p=Point(0.0,0.0), Vector v=Vector(0.0,0.0)):p(p),v(v){
        angle=atan2(v.y , v.x);
    }
    bool operator <(const Line &L)const{
        return angle<L.angle;
    }
}Line;

/* 用有向直線A->B 切割in，如果退化，可能會變成一點或線段 */
void cutPolygonBy2Point(Polygon in,Polygon &ou, Point A,Point B){
    ou.n=0;
    for(int i=0;i<in.n;i++){
        Point C = in.p[i];
        Point D = in.p[(i+1)&in.n];
        if(dcmp( (B-A)^(C-A) )>=0)ou.p[ou.n++]=C;
        if(dcmp( (B-A)^(C-D) ) !=0 ){
            Point ip;
            int ret=get_inter_point(Line_f(A,B), Line_f(C,D), ip);
            if(isPointOnSegment(ip,C,D))ou.p[ou.n++]=ip;
        }
    }
}
// tar是否在有向直線L的左側(線上不算)
bool isPointOnLeft(Line L,Point tar){   
    return dcmp( L.v^(tar-L.p) )>0;
}
// 兩直線交點，假定交點唯一存在
Point getIntersection(Line a,Line b){
    Vector u = a.p - b.p;
    double t = ( b.v^u )/( a.v^b.v );
    return a.p+a.v*t;
}

/* 計算半平面交 O(NlogN) */
void halfPlaneIntersection(Line L[],int Ln, Point poly[], int &polyn){
    sort(L,L+Ln);           //按極角排序
    int first=0,last=0;
    Point p[MAXLN];  // p[i]是deq[i]和deq[i+1]的交點
    Line deq[MAXLN];
    deq[0]=L[0];            // 初始化只有一個半平面
    for(int i=1;i<Ln;i++){
        while(first<last && !isPointOnLeft(L[i],p[last-1]))last--;
        while(first<last && !isPointOnLeft(L[i],p[first]))first++;
        deq[++last] = L[i];
        if(dcmp( deq[last].v ^ deq[last-1].v )==0){
            // 兩向量平行且同向，取內側的
            last--;
            if(isPointOnLeft(deq[last],L[i].p))deq[last]=L[i];
        }
        if(first<last)p[last-1]=getIntersection(deq[last-1],deq[last]);
    }
    while(first<last && !isPointOnLeft(deq[first],p[last-1]))last--;
    // 刪除無用平面(*)
    if(last - first<=1){    // 空集(* *)
        polyn=0;
        return;
    }
    p[last] = getIntersection(deq[last],deq[first]);
// 計算首尾兩個平面的交點

    polyn=0;
    for(int i=first;i<=last;i++)poly[polyn++]=p[i];
}
