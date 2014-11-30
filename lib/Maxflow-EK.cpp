#define MAXN 1033
#define inf ((int)1e9)
#define MAXQ 1033

int e[ MAXN ][ MAXN ] , e_num[ MAXN ];
int cap[ MAXN ][ MAXN ] , flo[ MAXN ][ MAXN ];
int vis[ MAXN ] , pat[ MAXN ];
int q[ MAXQ ],tail,head;

int bfs(int s,int t){
    int i , u , v ;
    head = 0 , tail = 1;
    q[0] = s;
    while( head < tail ){
        u = q[head%MAXQ];
        ++ head;
        vis[u] = 1;
        if( u == t ) return 1;
        for(i=0;i<e_num[u];++i){
            v = e[u][i];
            if(vis[v]) continue;
            if( cap[u][v] - flo[u][v] >0 || flo[v][u] > 0)
                pat[v] = u , q[(tail++)%MAXQ] = v;
        }
    }
    return 0;
}
int f_flow(int s,int t){
    int i,pre,f=inf,tmp;
    for(i = t ; i!=s ; i = pre){
        pre=pat[i];
        tmp=cap[pre][i]-flo[pre][i];
        if(tmp>0){
            if(tmp<f)f=tmp;
        }else{
            if(flo[i][pre]<f)f=flo[i][pre];
        }
    }
    for(i = t ; i!=s ; i = pre){
        pre = pat[i];
        tmp = cap[pre][i] - flo[pre][i];
        if(tmp > 0) 	flo[pre][i] += f;
        else      	flo[i][pre] -= f;
    }
    return f;
}
int Edmonds_karp(int s,int t){
    int ret=0;
    while(1){
        memset(vis,0,sizeof(vis));
        if(bfs(s,t)==0)break;
        ret+=f_flow(s,t);
    }
    return ret;
}
