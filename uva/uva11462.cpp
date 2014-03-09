#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int v[2000000];
int main(){
    int n;
    while(scanf("%d",&n), n){
        for(int i=0; i<n; i++)
            scanf("%d", &v[i]);
        sort(v, v+n);
        for(int i=0; i<n; i++){
            if(i)  printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }
    return 0;
}
