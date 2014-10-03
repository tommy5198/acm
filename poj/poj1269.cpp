// cross
#include<iostream>
#include<cstdio>
using namespace std;

struct point{
    double x,y;
};

struct vec{
    point st,en;
};

double cross(point p1,point p2,point p3,point p4){      //p2p1->p4p3
    return (p1.x-p2.x)*(p3.y-p4.y)-(p3.x-p4.x)*(p1.y-p2.y);
}

double m(point p1,point p2){
    return (p2.y-p1.y)/(p2.x-p1.x);
}

int main(){
    int n;
    point p[4];
    double d[4];
    double a[2],b[2];
    double x,y;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    while(cin>>n){
        while(n--){
            for(int i=0;i<4;i++)
                cin>>p[i].x>>p[i].y;
            d[0]=cross(p[0],p[2],p[3],p[2]);
            d[1]=cross(p[1],p[2],p[3],p[2]);
            d[2]=cross(p[2],p[0],p[1],p[0]);
            d[3]=cross(p[3],p[0],p[1],p[0]);
            a[0]=m(p[0],p[1]);
            a[1]=m(p[2],p[3]);
            
            if( (p[0].x == p[1].x && p[2].x == p[3].x) || a[0] == a[1]){
                if(d[2]*d[3])
                    cout<<"NONE"<<endl;
                else
                    cout<<"LINE"<<endl;
            }else{
                
                b[0]=p[0].y-p[0].x*a[0];
                b[1]=p[2].y-p[2].x*a[1];
                
                if(p[0].x == p[1].x){
                    x=p[0].x;
                    y=a[1]*x+b[1];
                }
                else if(p[2].x == p[3].x){
                    x=p[2].x;
                    y=a[0]*x+b[0];
                }
                else{
                    x=(b[1]-b[0])/(a[0]-a[1]);
                    y=a[0]*x+b[0];
                }
                    //cout<<a[0]dd<<" "<<b[0]<<" ";
                printf("POINT %.2f %.2f\n",x,y);
            }   
            //  cout<<m(p[0],p[1])<<" "<<m(p[2],p[3])<<" ";
           // cout<<cross(p[0],p[1],p[0],p[3])<<endl;
        }

    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
