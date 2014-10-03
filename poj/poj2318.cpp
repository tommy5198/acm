// cross
#include<iostream>
#include<cstring>
using namespace std;

struct point{
    float x,y;
};

double cross(point p1,point p2,point p3){
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

point bin[5001][2];
int toy[5002];

int main(){
    int n,m;
    double x1,y1,x2,y2;
    while(cin>>n,n){
        cin>>m>>x1>>y1>>x2>>y2;
        memset(bin,0,sizeof(bin));
        memset(toy,0,sizeof(toy));
        
        for(int i=0;i<n;i++){
            cin>>bin[i][0].x>>bin[i][1].x;
            bin[i][0].y=y1;
            bin[i][1].y=y2;
        }
        for(int i=0;i<m;i++){
            point t;
            cin>>t.x>>t.y;
            for(int j=0;j<n;j++){
                if(cross(t,bin[j][0],bin[j][1]) < 0){
                    toy[j]++;
                    break;
                }
                if(j==n-1)
                    toy[n]++;
            }
        }
        for(int i=0;i<=n;i++)
            cout<<i<<": "<<toy[i]<<endl;
        cout<<endl;
    }
    return 0;
}
