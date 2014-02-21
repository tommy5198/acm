#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        printf("Case %d:\n", i);
        int n;
        char m[12][12] = {{0}};
        int d[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
        scanf("%d", &n);
        for(int x=1; x<=n; x++)
            for(int y=1; y<=n; y++)
                cin>>m[x][y];
        for(int x=1; x<=n; x++){
            for(int y=1; y<=n; y++){
                if(m[x][y] == '.'){
                    char c='A';
                    for(int D=0; D<4; D++)
                        if(m[x+d[D][0]][y+d[D][1]] == c){
                            c++;
                            D=-1;
                        }
                    m[x][y] = c;
                }
                cout<<m[x][y];
            }
            cout<<endl;
        }
    }
    return 0;
}
