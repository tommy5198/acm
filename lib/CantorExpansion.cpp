int factorial[MAXN]={1,1,2,6,24,120,720,5040,40320};
int StN_CantorExpansion(int s[],int n){  //全排列對應1~N!
    int i,j,ret=0,cnt;
    for( i=0 ; i<n ; i++){
        for( j=i+1 ,cnt=0 ; j<n ; j++) if(s[j]<s[i]) cnt++;
        ret += cnt * factorial[n-i-1];
    }
    return ret+1;
}
// 1~N!對應全排列
void NtS_CantorExpansion(int s[],int n,int idx){
    bool vis[MAXN]={false};
    int i , num , cnt;
    idx--;
    for( i=0 ; i<n ; i++){
        cnt = idx/factorial[n-i-1];
        for(num=1 ; num<=n ; num++)
            if(!vis[num]) if( cnt-- ==0)break;
        s[i] = num , vis[num] = true;
        idx %= factorial[n-i-1];
    }
}
