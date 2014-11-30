// graph[0][1]=graph[1][0]=true; 無向圖建邊
// dfnlow(0,0); 呼叫=> root點
int dfn[MAX],low[MAX],answer[MAX],depth=1,ansc=0;
bool graph[MAX][MAX];
void dfnlow(int u,int v)
{
  int w;
  bool yes=0;
  int child=0;
  dfn[u]=low[u]=depth++;
  for(w=0;w<MAX;w++)
    if(graph[u][w])
    {
      if(dfn[w]<0)
      {
        dfnlow(w,u);
        child++;
        low[u]=(low[u]<low[w])?low[u]:low[w];
        if(low[w]>=dfn[u])
        {
          yes=1;
          /*if(low[w]!=dfn[u])cout<<u<<"-"<<w<<endl;
		  找cut edge u-w */
        }
      }
      else if(w!=v)
        low[u]=(low[u]<dfn[w])?low[u]:dfn[w];
    }
  if( (u==v&&child>1 ) || (u!=v&&yes) )
    answer[ansc++]=u;
}
