#include<cstdio>

int nt[200002], v[200001], nv[200001];

int fn(int x){
    return nt[x]==x ? x : nt[x]=fn(nt[x]);
}

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &v[i]);
        nt[i] = i;
        nv[i] = 0;
    }
    nt[n+1] = n+1;
    scanf("%d", &m);
    while(m--){
        int cmd, a, b;
        scanf("%d", &cmd);
        if(cmd == 1){
            scanf("%d%d", &a, &b);
            int now = fn(a);
            while(now <=n && b){
                int tmp = b>v[now]-nv[now] ? v[now]-nv[now] : b;
                nv[now] += tmp;
                b -= tmp;
                if(v[now] == nv[now]) nt[now]++;
                now = fn(now);
            }
        }else{
            scanf("%d", &a);
            printf("%d\n", nv[a]);
        }
    }
    return 0;
}
