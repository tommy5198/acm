#include<cstdio>

 void init(){
     int k, a, b;
     scanf("%d", &n);
     scanf("%d", &k);
     for(int i=0; i<k; i++)
         scanf("%d%d", gap[i], gap[i]+1);
     for(int i=0; i<n-1; i++){
         scanf("%d", &k);
         while(k--){
             scanf("%d%d", &a, &b);
             for(int j=0; j<10; j++)
                 inter(a, b, j);
         }
     }
 }

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        sol();
    }
    return 0;
}
