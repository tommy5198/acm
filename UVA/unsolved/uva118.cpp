#include<iostream>
#include<map>
#include<cstring>
using namespace std;


int main(){

    char t[4][4]={{'N','W','S','E'},{'W','S','E','N'},{'S','E','N','W'},{'E','N','W','S'}};
    int w[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
    map<char,int> mp;
    bool prelost[51][51];
    int n,m,x,y;
    char dir;
    string route;

    memset(prelost,false,sizeof(prelost));
    mp['N']=0;
    mp['W']=1;
    mp['S']=2;
    mp['E']=3;
    cin>>n>>m;
    while(cin>>x>>y>>dir){
        cin.ignore();
        getline(cin,route);
        int turnl=0;
        bool lost=false;
        for(int i=0;i<route.size();i++){
            switch(route[i]){
                case 'L':
                    turnl++;
                    break;
                case 'R':
                    turnl--;
                    break;
                case 'F':
                    turnl%=4;
                    turnl=(turnl>=0)?turnl:turnl+4;
                    int tx=x+w[mp[t[mp[dir]][turnl]]][0];
                    int ty=y+w[mp[t[mp[dir]][turnl]]][1];
                    if(tx<=n && ty<=m && tx>=0 && ty>=0){
                        x=tx;
                        y=ty;
                    }else if(!prelost[x][y]){
                        lost=true;
                        prelost[x][y]=true;
                    }
                    break;
            }
            if(lost)
                break;
        }
        cout<<x<<" "<<y<<" "<<t[mp[dir]][turnl];
        if(lost)
            cout<<" LOST";
        cout<<endl;
    }
    return 0;
}

