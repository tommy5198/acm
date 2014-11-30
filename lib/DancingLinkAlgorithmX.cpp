#include <stdio.h>
#define DLX_MAX_ROW 33
#define DLX_MAX_COL 333
#define DLX_MAX_NODE ((DLX_MAX_ROW)*(DLX_MAX_COL)+1)
#define DLX_HEAD 0
typedef struct DN
{
    int row,col;
    int L,R,U,D; 			/* Left Right Up Down */
}DN;
DN  Dn[ DLX_MAX_NODE ];	/* DLX node */
int Rh[ DLX_MAX_ROW ];		/* Row head */
int Cs[ DLX_MAX_COL ];		/* Column size */
int Ar[ DLX_MAX_ROW ];		/* Answer row */
int Row,Col,Nc,Dl;			/* Node cnt , dlx limit */

/* For RepeatCover */
int Cm[DLX_MAX_COL];/* Column mark */

void DLX_init(int dlx_row,int dlx_col)
{
    int i;
    Col=dlx_col;
    Row=dlx_row;
    Dn[DLX_HEAD].L=Col;
    Dn[DLX_HEAD].R=1;
    Dn[DLX_HEAD].U=DLX_HEAD;
    Dn[DLX_HEAD].D=DLX_HEAD;
    for(i=1;i<=Col;++i){
        Dn[i].L=i-1;
        Dn[i].R=i+1;
        Dn[i].U=i;
        Dn[i].D=i;
        Dn[i].col=i;
        Dn[i].row=0;
        Cs[i]=0;
    }
    Dn[Col].R=DLX_HEAD;
    Nc=Col+1;
    for(i=1;i<=Row;++i)Rh[i]=-1;
}

void DLX_add_back(int dlx_row,int dlx_col)
{
    Dn[Nc].col=dlx_col;
    Dn[Nc].row=dlx_row;
    if(Rh[dlx_row]==-1){
        Rh[dlx_row]=Nc;
        Dn[Nc].L=Nc;
        Dn[Nc].R=Nc;
        Dn[Nc].U=Dn[dlx_col].U;
        Dn[Nc].D=dlx_col;
        Dn[ Dn[dlx_col].U ].D=Nc;
        Dn[dlx_col].U=Nc;
    }else{
        Dn[Nc].L = Dn[ Rh[dlx_row] ].L;
        Dn[Nc].R = Rh[dlx_row];
        Dn[Nc].U = Dn[dlx_col].U;
        Dn[Nc].D = dlx_col;
        Dn[ Dn[Nc].L ].R = Nc;
        /* Dn[Dn[Nc].R].L=Nc; */
        Dn[ Rh[dlx_row] ].L = Nc;
        Dn[ Dn[dlx_col].U ].D = Nc;
        Dn[dlx_col].U = Nc;
    }
    ++Nc;
    ++Cs[dlx_col];
}

void DLX_EC_remove(int dlx_col)
{
    int i,j;
    Dn[ Dn[dlx_col].L ].R = Dn[dlx_col].R;
    Dn[ Dn[dlx_col].R ].L = Dn[dlx_col].L;
    for(i=Dn[dlx_col].D;i!=dlx_col;i=Dn[i].D){
        for(j=Dn[i].R;j!=i;j=Dn[j].R){
            Dn[ Dn[j].D ].U = Dn[j].U;
            Dn[ Dn[j].U ].D = Dn[j].D;
            --Cs[ Dn[j].col ];
        }
    }
}
void DLX_EC_resume(int dlx_col)
{
    int i,j;
    for(i=Dn[dlx_col].U;i!=dlx_col;i=Dn[i].U){
        for(j=Dn[i].L;j!=i;j=Dn[j].L){
            Dn[ Dn[j].D ].U=j;
            Dn[ Dn[j].U ].D=j;
            ++Cs[ Dn[j].col ];
        }
    }
    Dn[ Dn[dlx_col].L ].R=dlx_col;
    Dn[ Dn[dlx_col].R ].L=dlx_col;
}
int DLX_EC_search(int dlx_k)
{
    int dlx_choose_col=-1;
    int dlx_chosen_size=-1;
    int i,j,ret;
    if(Dn[DLX_HEAD].R==DLX_HEAD){
        Dl=dlx_k;
        return 1;
    }
    for(i=Dn[DLX_HEAD].R;i!=DLX_HEAD;i=Dn[i].R){
        if(dlx_chosen_size==-1 || Cs[i]<dlx_chosen_size){
            dlx_chosen_size=Cs[i];
            dlx_choose_col=i;
        }
    }
    DLX_EC_remove(dlx_choose_col);
    for(i=Dn[dlx_choose_col].D; \
        i!=dlx_choose_col; \
        i=Dn[i].D){
        
        Ar[dlx_k]=Dn[i].row;
        for(j=Dn[i].R;j!=i;j=Dn[j].R)
            DLX_EC_remove(Dn[j].col);
        ret=DLX_EC_search(dlx_k+1);
        if(ret==1)return 1;
        for(j=Dn[i].L;j!=i;j=Dn[j].L)
            DLX_EC_resume(Dn[j].col);
    }
    DLX_EC_resume(dlx_choose_col);
    return 0;
}

void DLX_RC_remove(int dlx_col)
{
    int i;
    for(i=Dn[dlx_col].D;i!=dlx_col;i=Dn[i].D){
        Dn[ Dn[i].R ].L = Dn[i].L;
        Dn[ Dn[i].L ].R = Dn[i].R;
    }
}
void DLX_RC_resume(int dlx_col)
{
    int i;
    for(i=Dn[dlx_col].U;i!=dlx_col;i=Dn[i].U){
        Dn[ Dn[i].R ].L=i;
        Dn[ Dn[i].L ].R=i;
    }
}
int DLX_RC_h()
{
    int i,j,k;
    int ret=0;
    for(i=1;i<=Col;++i)Cm[i]=0;
    for(k=Dn[DLX_HEAD].R;k!=DLX_HEAD;k=Dn[k].R){
        if(Cm[k]==0){
            ++ret;
            Cm[k]=1;
            for(i=Dn[k].D;i!=k;i=Dn[i].D)
                for(j=Dn[i].R;j!=i;j=Dn[j].R)
                    Cm[Dn[j].col]=1;
        }
    }
    return ret;
}
int DLX_RC_search_up(int dlx_k)
{
    int dlx_choose_col=-1;
    int dlx_chosen_size=-1;
    int i,j,ret;
    int dlx_h=DLX_RC_h();
    if(dlx_k+dlx_h>=Dl)return 0;
	/* down should update Dl limit and answer row here */
    if(Dn[DLX_HEAD].R==DLX_HEAD){
        Dl=dlx_k;
        return 1;
    }
    for(i=Dn[DLX_HEAD].R;i!=DLX_HEAD;i=Dn[i].R){
        if(dlx_chosen_size==-1 || Cs[i]<dlx_chosen_size){
            dlx_chosen_size=Cs[i];
            dlx_choose_col=i;
        }
    }
    for(i=Dn[dlx_choose_col].D; \
        i!=dlx_choose_col; \
        i=Dn[i].D){
        
        DLX_RC_remove(i);
        for(j=Dn[i].R;j!=i;j=Dn[j].R)
            DLX_RC_remove(j);
        Ar[dlx_k]=Dn[i].row;
        ret=DLX_RC_search_up(dlx_k+1);
        /* up return */
		if(ret==1)return 1;
        /* down dont return */
        for(j=Dn[i].L;j!=i;j=Dn[j].L)
            DLX_RC_resume(j);
        DLX_RC_resume(i);
    }
    return 0;
}
int DLX_RC_IDAstar()
{
    Dl=DLX_RC_h();
    while(DLX_RC_search_up(0)==0){
        if(Dl>Row)return -1;
        ++Dl;
    }
    return Dl;
}
int main()
{
    int map[DLX_MAX_ROW][DLX_MAX_COL],N,M,i,j,cc;
    while(scanf("%d%d",&M,&N)!=EOF){
        for(i=1;i<=M;i++)
            for(j=1;j<=N;j++)
                scanf("%d",&map[i][j]);
        DLX_init(M,N);
        for(i=1;i<=M;i++)
            for(j=1;j<=N;j++)
                if(map[i][j]==1)
                    DLX_add_back(i,j);
        puts("-----test beg-----");
		/***  RepeatCover  ***/
        cc=DLX_RC_IDAstar();
        printf("%d\n",Dl);
        for(i=0;i<cc;++i)
            printf("row %d\n",Ar[i]);

        /***  ExactCover  ***/
        cc=DLX_EC_search(0);
        if(cc==1){
            puts("Yes");
            printf("deep %d\n",Dl);
            for(i=0;i<Dl;i++)
                printf("%d ",Ar[i]);
            putchar('\n');
        }else{
            puts("No");
        }  /* End */
    }
    return 0;
}
