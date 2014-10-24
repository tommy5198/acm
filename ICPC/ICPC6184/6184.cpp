#include <cstdio>
using namespace std;
#define MAXN 33
#define MAXD 52
typedef struct MAT{
    int m,n;
    int v[MAXD][MAXD];
    MAT(int _m=0,int _n=0):n(_n),m(_m){
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                v[i][j]=0;
            }
        }
    }
}MAT;


int N,M,A,B,C,T;
int coef[3];
MAT S0;
MAT po[MAXN];
MAT ans;

MAT operator*(MAT &a,MAT &b)
{
    MAT ret=MAT(a.m,b.n);
    int i,j,k;
    for(i=0;i<a.m;i++){
        for(j=0;j<b.n;j++){
            for(k=0;k<a.n;k++){
                ret.v[i][j]+=(a.v[i][k]*b.v[k][j])%M;
                ret.v[i][j]%=M;
            }
        }
    }
    return ret;
}

int main()
{
    int i,j,k;
    
    while(scanf("%d%d%d%d%d%d",&N,&M,&A,&B,&C,&T)!=EOF){
        if(N==0 && M==0 && A==0 && B==0 && C==0 && T==0)break;

        S0=MAT(N,1);
        for(i=0;i<N;i++){
            scanf("%d",&S0.v[i][0]);
        }
        if(T==0){
            for(i=0;i<N;i++){
                printf("%d",S0.v[i][0]);
                if(i!=N-1)printf(" ");
                else puts("");
            }
            continue;
        }
        coef[0]=A;
        coef[1]=B;
        coef[2]=C;
        po[0]=MAT(N,N);
        for(i=0;i<N;i++){
            for(j=i-1,k=0;k<3;j++,k++){
                if(j<0 || j>=N)continue;
                po[0].v[i][j]=coef[k];
            }
        }

        /* TEST po  * /
        printf("po 0   %d   %d\n",po[0].m,po[0].n);
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                printf("%d ",po[0].v[i][j]);
            }
            puts("");
        }
        /**/

        for(i=1,j=2;j<=T;j<<=1,i++){
            po[i]=po[i-1]*po[i-1];
        }
        ans=MAT(N,N);
        for(i=0;i<N;i++){
            ans.v[i][i]=1;
        }
        for(i=0,j=1;j<=T;j<<=1,i++){
            if(T&j){
                ans=ans*po[i];
            }
        }
        ans=ans*S0;
        //printf("ans \n");
        for(i=0;i<N;i++){
            printf("%d",ans.v[i][0]);
            if(i!=N-1)printf(" ");
            else puts("");
        }
    }
    return 0;
}
