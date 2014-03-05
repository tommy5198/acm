#include<cstdio>

struct Arc{
    double r, s, t;
    bool operator<(const Arc &t)const{
        return r > t.r  
    }
}arc[20000];
int n;
double cover(double src, double dst, int index){
    double r = arc[index].r, s = arc[index].s, t = arc[index].t;
    if(!index)
        return 0 + cover(s, t, 1);
    if(index == n)
        return 0;
    if(s >= src && t <= dst)
        return area(s, t, r) + cover(src, dst, index+1);
    if(s < src && t >= src && t <= dst)
        return area(src, t, r) + cover(s, dst, index+1);
    if(s >= src && s <= dst && r > dst)
        return area(s, dst, r) + cover(src, t, index+1);
    if(s < src && t > dst)
        return area(src, dst, r) + cover(s, t, index+1);
    return cover(s, t, index+1) + cover(src, dst, index+1);

}

int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        double r, s, t;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%lf%lf%lf", arc[i].r, arc[i].s, arc[i].t)
        sort(arc, arc+n);
        cover(0, 0, 0);
    }
    return 0;
}
