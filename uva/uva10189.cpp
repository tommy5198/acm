#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

int main(){
    int x,y,t=1;
    std::ios_base::sync_with_stdio(false);
    while(cin>>y>>x){
        if(!x&&!y)
            break;
        char mine[y+2][x+2];
        memset(mine,0,sizeof(char)*(y+2)*(x+2));
        for(int i=1;i<y+1;i++)
            for(int j=1;j<x+1;j++)
                cin>>mine[i][j];
        for(int i=1;i<y+1;i++)
            for(int j=1;j<x+1;j++){
                int c=0;
                if(mine[i][j]=='.'){
                    if(mine[i+1][j]=='*')
                        c++;
                    if(mine[i][j+1]=='*')
                        c++;
                    if(mine[i+1][j+1]=='*')
                        c++;
                    if(mine[i+1][j-1]=='*')
                        c++;
                    if(mine[i-1][j+1]=='*')
                        c++;
                    if(mine[i-1][j]=='*')
                        c++;
                    if(mine[i-1][j-1]=='*')
                        c++;
                    if(mine[i][j-1]=='*')
                        c++;
                    mine[i][j]=c+48;
                }
            }
        if(t>1)
        cout<<endl;
        cout<<"Field #"<<t<<":"<<endl;
        t++;
        for(int i=1;i<y+1;i++){
            for(int j=1;j<x+1;j++)
                cout<<mine[i][j];
            cout<<endl;
        }


    }
    return 0;
}
