//need rewrite
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=1001;
const int inf=1<<30;

char str[maxn];
char map[maxn][maxn];
int tim[maxn][maxn];
bool vis[maxn][maxn];
int n,m,xpos,ypos;
int dir[4][2]={1,0,-1,0,0,1,0,-1};

struct Node
{
    int x,y;
};

struct No
{
    int x,y,t;
};

void bfs1();
void bfs2();

int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        memset(vis,0,sizeof(vis));

        for(i=0;i<n;++i)
        {
            scanf("%s",str);
            for(j=0;j<m;++j)
            {
                map[i][j]=str[j];

                if(map[i][j]=='F')
                tim[i][j]=0;
                else
                tim[i][j]=inf;

                if(map[i][j]=='J')
                {
                    xpos=i;
                    ypos=j;
                    map[i][j]='.';
                }
            }
        }
        bfs1();
        bfs2();
    }
    return 0;
}

void bfs1()
{
    int i,j;
    queue<Node> q;
    Node node,no;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            if(map[i][j]=='F')
            {
                no.x=i;no.y=j;
                q.push(no);
            }
        }
    }
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        for(i=0;i<4;++i)
        {
            no.x=node.x+dir[i][0];
            no.y=node.y+dir[i][1];
            if(map[no.x][no.y]=='.' && no.x>=0 && no.x<n && no.y>=0 && no.y<m && tim[node.x][node.y]+1<tim[no.x][no.y])
            {
                q.push(no);
                tim[no.x][no.y]=tim[node.x][node.y]+1;
            }
        }
    }
}

void bfs2()
{
    No node,no;
    int i,j;
    node.x=xpos;
    node.y=ypos;
    node.t=0;
    queue<No> q;
    q.push(node);
    vis[node.x][node.y]=1;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        if(node.x==0 || node.x==n-1 || node.y==0 || node.y==m-1)
        {
            printf("%d\n",node.t+1);
            return ;
        }

        for(i=0;i<4;++i)
        {
            no.x=node.x+dir[i][0];
            no.y=node.y+dir[i][1];
            no.t=node.t+1;
            if(!vis[no.x][no.y]&&no.x>=0 && no.x<n && no.y>=0 && no.y<m && no.t<tim[no.x][no.y] && map[no.x][no.y]=='.')
            {
                vis[no.x][no.y]=1;
                q.push(no);
            }
        }
    }
    puts("IMPOSSIBLE");
}
