#include<cstdio>

int p[300];
char m[300][301];

void dfs(int nw, int v)
{
    if(nw < idx[v])
        idx =

}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", p+i);
        idx[p[i]] = i;
    }
    for(int i=0; i<n; i++)
        scanf("%s", m[i]);
    //dc(0, n-1);
    for(int i=1; i<=n; i++)
        dfs(idx[i]);
    return 0;
}
