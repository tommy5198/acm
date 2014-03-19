#include<cstdio>
#include<map>

int main(){
    int n;
    int num[100000];
    std::map<int, bool> m;
    int a = 0, b = 0, cnt = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);
    for(int i=0; i<n; i++){
        a += num[i];
        m[a] = true;
    }
    for(int i=0; i<n; i++){
        b += num[n-i-1];
        if(m[b]) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
