#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 53
typedef struct COOD{
    int x,y;
    COOD(int xx=0,int yy=0):x(xx),y(yy){}
}COOD;
typedef struct RET{
    int l,r,t,b;
    COOD s[4];
}RET;

RET ret[MAXN];
int F,V,E,C;
int hs[MAXN];
int rk[MAXN];
int kk[2];
int n;
vector<int>ori[2];
map<int,int>ma[2];
int  cnt[MAXN*4][MAXN*4][2];
bool isv[MAXN*4][MAXN*4];


int fs(int x){
    if(hs[x]!=x)hs[x]=fs(hs[x]);
    return hs[x];
}
void us(int x,int y){
    if(rk[x]<rk[y])
        hs[x]=y;
    else{
        hs[y]=x;
        if(rk[x]==rk[y])rk[x]++;
    }
}

void check3(COOD &ta,COOD &tb,COOD &tc,COOD &td){
    COOD tt= COOD(tc.x,ta.y);
    if(tt.x<ta.x)return;
    if(tt.x>tb.x)return;
    if(tt.y<tc.y)return;
    if(tt.y>td.y)return;
    isv[tt.x][tt.y]=true;
}
void check2(int ri,int rj){
    check3(ret[ri].s[0],ret[ri].s[1],ret[rj].s[0],ret[rj].s[2]);
    check3(ret[ri].s[0],ret[ri].s[1],ret[rj].s[1],ret[rj].s[3]);
    check3(ret[ri].s[2],ret[ri].s[3],ret[rj].s[0],ret[rj].s[2]);
    check3(ret[ri].s[2],ret[ri].s[3],ret[rj].s[1],ret[rj].s[3]);
}
void check1(int ri,int rj){
    int tc[2][4];
    int tmap[4][4];
    int i,j,u,v,ll,rr,tt,bb;

    tc[0][0]=ret[ri].s[0].x;
    tc[0][1]=ret[ri].s[3].x;
    tc[0][2]=ret[rj].s[0].x;
    tc[0][3]=ret[rj].s[3].x;
    tc[1][0]=ret[ri].s[0].y;
    tc[1][1]=ret[ri].s[3].y;
    tc[1][2]=ret[rj].s[0].y;
    tc[1][3]=ret[rj].s[3].y;
    sort(tc[0],tc[0]+4);
    sort(tc[1],tc[1]+4);
    memset(tmap,0,sizeof(tmap));
    
    ll=rr=tt=bb=-1;
    for(i=0;i<4;i++){
        if(tc[0][i]==ret[ri].s[0].x && ll==-1)ll=i;
        if(tc[0][i]==ret[ri].s[3].x && rr==-1)rr=i;
        if(tc[1][i]==ret[ri].s[0].y && bb==-1)bb=i;
        if(tc[1][i]==ret[ri].s[3].y && tt==-1)tt=i;
    }
    /** /
    if(ri==2 || rj==2){
        printf("11  ll,rr,tt   %d %d %d %d\n",ll,rr,tt,bb);
    }
    /**/
    for(i=ll;i<=rr;i++)
        tmap[i][tt]=tmap[i][bb]=1;
    for(i=bb;i<=tt;i++)
        tmap[ll][i]=tmap[rr][i]=1;
    ll=rr=tt=bb=-1;
    for(i=0;i<4;i++){
        if(tc[0][i]==ret[rj].s[0].x && ll==-1)ll=i;
        if(tc[0][i]==ret[rj].s[3].x && rr==-1)rr=i;
        if(tc[1][i]==ret[rj].s[0].y && bb==-1)bb=i;
        if(tc[1][i]==ret[rj].s[3].y && tt==-1)tt=i;
    }

    /** /
    if(ri==2 || rj==2){
        printf("rij   %d %d\n",ri,rj);
        //for(i=ll;i<=rr;i++)tmap[i][tt]=tmap[i][bb]=2;
        //for(i=bb;i<=tt;i++)tmap[ll][i]=tmap[rr][i]=2;
        for(i=0;i<4;i++){
            printf("tmap   ");
            for(j=0;j<4;j++){
                printf("%d ",tmap[i][j]);
            }
            puts("");
        }
    }
    /**/


    for(i=ll;i<=rr;i++){
        if(tmap[i][tt]==1){
            u=fs(ri);
            v=fs(rj);
            if(u!=v){
                us(ri,rj);
            }
            return;
        }
        if(tmap[i][bb]==1){
            u=fs(ri);
            v=fs(rj);
            if(u!=v){
                us(ri,rj);
            }
            return;
        }
    }
    for(i=bb;i<=tt;i++){
        if(tmap[ll][i]==1){
            u=fs(ri);
            v=fs(rj);
            if(u!=v){
                us(ri,rj);
            }
            return;
        }
        if(tmap[rr][i]==1){
            u=fs(ri);
            v=fs(rj);
            if(u!=v){
                us(ri,rj);
            }
            return;
        }
    }

}





int main()
{
    int i,j;

    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        for(i=0;i<n;i++)hs[i]=i,rk[i]=1;
        memset(cnt,0,sizeof(cnt));
        memset(isv,false,sizeof(isv));
        ma[0].clear();
        ma[1].clear();
        ori[0].clear();
        ori[1].clear();
        F=V=E=C=0;

        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&ret[i].l,&ret[i].t,&ret[i].r,&ret[i].b);
            ori[0].push_back(ret[i].l);
            ori[0].push_back(ret[i].r);
            ori[1].push_back(ret[i].t);
            ori[1].push_back(ret[i].b);
        }
        sort(ori[0].begin(),ori[0].end());
        sort(ori[1].begin(),ori[1].end());
        kk[0]=kk[1]=0;
        for(j=0;j<2;j++){
            for(i=0;i<ori[j].size();i++){
                if(i==0 || ori[j][i]!=ori[j][i-1]){
                    ma[j][ ori[j][i] ]=++kk[j];
                }
            }
        }

        for(i=0;i<n;i++){
            int tl = ma[0][ret[i].l];
            int tr = ma[0][ret[i].r];
            int tt = ma[1][ret[i].t];
            int tb = ma[1][ret[i].b];
            ret[i].s[0]=COOD(tl,tb);
            ret[i].s[1]=COOD(tr,tb);
            ret[i].s[2]=COOD(tl,tt);
            ret[i].s[3]=COOD(tr,tt);

            cnt[tl][tb][0]++;
            cnt[tl][tb][1]++;

            cnt[tr][tb][0]--;
            cnt[tr][tb][1]++;

            cnt[tl][tt][0]++;
            cnt[tl][tt][1]--;

            cnt[tr][tt][0]--;
            cnt[tr][tt][1]--;

            isv[tl][tb]=true;
            isv[tr][tb]=true;
            isv[tl][tt]=true;
            isv[tr][tt]=true;
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                check1(i,j);
                check2(i,j);
                check2(j,i);
            }
        }
        /** /
        for(i=1;i<=kk[0];i++){
            printf("cnt 0  ");
            for(j=1;j<=kk[1];j++){
                printf("%d ",cnt[i][j][0]);
            }
            puts("");
        }
        for(i=1;i<=kk[0];i++){
            printf("cnt 1  ");
            for(j=1;j<=kk[1];j++){
                printf("%d ",cnt[i][j][1]);
            }
            puts("");
        }
        /**/
        for(i=1;i<=kk[0];i++){
            int ttt=0;
            for(j=1;j<=kk[1];j++){
                if(isv[i][j]){
                    V++;
                    if(ttt!=0)E++;
                    ttt+=cnt[i][j][1];
                }
            }
        }
        for(i=1;i<=kk[1];i++){
            int ttt=0;
            for(j=1;j<=kk[0];j++){
                if(isv[j][i]){
                    if(ttt!=0)E++;
                    ttt+=cnt[j][i][0];
                }
            }
        }
        for(i=0;i<n;i++){
            if(hs[i]==i)C++;
        }
        /** /
        for(i=0;i<n;i++){
            printf("ret %d   fs %d\n",i,fs(i));
        }
        /**/
        F=1+C+E-V;
        //printf("C %d   E %d   V %d   \n ans:",C,E,V);
        printf("%d\n",F);
    }

    return 0;
}

