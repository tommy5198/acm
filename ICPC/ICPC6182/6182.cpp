#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 144
int p2q2sum;
int m2n2sum;
int p,q;

char ifprime(){
    int m,n;

    p2q2sum=p*p+q*q;
    for(m=0;m*m<=p2q2sum;m++){
        for(n=0;m*m+n*n<=p2q2sum;n++){
            m2n2sum=m*m+n*n;
            if(m2n2sum<=1)continue;
            if(p2q2sum%m2n2sum)continue;
            if(p2q2sum==m2n2sum)continue;
            if((m*p+n*q)%m2n2sum==0 && (m*q-n*p)%m2n2sum==0){
                return 'C';
            }
            if((-m*p+n*q)%m2n2sum==0 && (-m*q-n*p)%m2n2sum==0){
                return 'C';
            }
            if((m*p-n*q)%m2n2sum==0 && (m*q+n*p)%m2n2sum==0){
                return 'C';
            }
            if((-m*p-n*q)%m2n2sum==0 && (-m*q+n*p)%m2n2sum==0){
                return 'C';
            }
        }
    }
    return 'P';
}

int main()
{
    int cas;

    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&p,&q);
        printf("%c\n",ifprime()); 
    } 
    return 0;
}
