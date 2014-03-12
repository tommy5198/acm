#include<cstdio>

int p[50001];

int n, m;

int count(){
    int cmd, a, b;
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &cmd, &a, &b);
        if(cmd == 1){
            if(p[a] < 0 && p[b]<0 && p[a] != p[b])
                lie++;
            else
                uni(a, b);
        }else{
            if(p[a] < 0 && p[b] < 0){
                if(p[a] == p[b] || (-p[a]+1)%3 != -p[a] )
                    lie++;
            else
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    printf("%d\n", count());
    return 0;
}
