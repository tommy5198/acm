#include<cstdio>
#include<algorithm>

int main(){
    int n, data[100005], qry;
    char t[5];
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &data[i]);
    std::sort(data+1, data+n+1);
    scanf("%s%d", t, &n);
    for(int i=0; i<n; i++){
        scanf("%d", &qry);
        printf("%d\n", data[qry]);
    }
    return 0;
}
