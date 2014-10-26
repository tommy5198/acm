#include <cstdio>

using namespace std;
#define MAXN 23
#define MAXL 133

int cnt[MAXL];
int nxt[MAXN];
int pla[MAXN];
int dir[MAXN];
int n,l,ant;
int ans_t,ans_a;


int main()
{
    int t,i;
    char tmp[MAXL];

    while(scanf("%d%d",&n,&l)!=EOF){
        if(n==0 && l==0)break;
        ant=n;
        for(i=0;i<n;i++){
            scanf("%s%d",tmp,&pla[i]);
            if(tmp[0]=='R')dir[i]=1;
            else dir[i]=-1;
        }
        /*
        puts("end input");
        for(i=0;i<n;i++){
            printf("ant %d: %d %d\n",i+1,pla[i],dir[i]);
        }
        */
        ans_t=0;
        for(t=1;ant>0;t++){
            for(i=0;i<=l;i++)cnt[i]=0;
            for(i=0;i<n;i++){
                if(pla[i]==0 || pla[i]==l)continue;
                nxt[i]=pla[i]+dir[i];
                cnt[ nxt[i] ]++;
            }
            for(i=0;i<n;i++){
                if(pla[i]==0 || pla[i]==l)continue;
                if(cnt[ nxt[i] ]>1)dir[i]*=-1;
                pla[i]=nxt[i];

                if(pla[i]==0 || pla[i]== l){
                    if(pla[i]==0){
                        if(t>=ans_t)ans_t=t,ans_a=i+1;
                    }else{
                        if(t>ans_t)ans_t=t,ans_a=i+1;
                    }
                    ant--;
                }
            }
        }
        printf("%d %d\n",ans_t,ans_a);
    }

    return 0;
}
