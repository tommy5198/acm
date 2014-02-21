#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n;
int ca=1;
int img[27][27];
int eagle[27][27];
int count;
int w[3]={1,0,-1};

void dfs(int x,int y){
    eagle[x][y]=count;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(img[x+w[i]][y+w[j]] && !eagle[x+w[i]][y+w[j]])
                dfs(x+w[i],y+w[j]);
}

int main(){


    while(cin>>n){
        count=0;
        memset(eagle,0,sizeof(eagle));
        memset(img,0,sizeof(img));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%1d",&img[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(img[i][j] && !eagle[i][j]){
                    ++count;
                    dfs(i,j);
                }

        printf("Image number %d contains %d war eagles.\n",ca,count);
        ca++;
    }
    return 0;
}
