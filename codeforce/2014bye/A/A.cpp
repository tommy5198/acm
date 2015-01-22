#include<cstdio>
int e[30001];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        e[i] = i+tmp;
    }
    int i;
    for(i=1; i<n; i++) {
        if(i == m) break;
        i = e[i]-1;
    }
    puts(i == m ? "YES" : "NO");
    return 0;
}
