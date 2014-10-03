// cross
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct point{
    double x,y;
};

double cross(point p1,point p2,point p3,point p4){
    return (p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x);
}

bool onLine(point p1,point p2,point t){
    if(min(p1.x,p2.x) <= t.x && max(p1.x,p2.x) >= t.x)
        if(min(p1.y,p2.y) <= t.y && max(p1.y,p2.y) >= t.y)
            return true;
    return false;
}

point s[100000][2];
vector<int> top;
double d[4];

bool isTop(point p1,point p2,point p3,point p4){
    d[0]=cross(p1,p3,p4,p3);
    d[1]=cross(p2,p3,p4,p3);
    d[2]=cross(p3,p1,p2,p1);
    d[3]=cross(p4,p1,p2,p1);
    if(d[0]*d[1]<0 && d[2]*d[3]<0)  return true;
    if(!d[0] && onLine(p3,p4,p1))   return true;
    if(!d[1] && onLine(p3,p4,p2))   return true;
    if(!d[2] && onLine(p1,p2,p3))   return true;
    if(!d[3] && onLine(p1,p2,p4))   return true;
    return false;
}

int main(){
    
    int n;
    while(cin>>n,n){
        memset(s,0,sizeof(s));
        top.clear();
        for(int i=0;i<n;i++){
            cin>>s[i][0].x>>s[i][0].y>>s[i][1].x>>s[i][1].y;
            for(int j=0;j<top.size();j++){
                if(isTop(s[i][0],s[i][1],s[top[j]][0],s[top[j]][1])){
                    top.erase(top.begin()+j);
                    j--;
                }
            }
            top.push_back(i);
        }
        cout<<"Top sticks:";
        for(int i=0;i<top.size();i++){
            if(i == top.size()-1)
                cout<<" "<<top[i]+1<<"."<<endl;
            else
                cout<<" "<<top[i]+1<<",";
        }
    }
    return 0;
}

