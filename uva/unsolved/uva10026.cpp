//recheck
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct{
    int d;
    int p;
    int n;
}j;

bool cmp(j x,j y){
    if(x.d*y.p < x.p*y.d)
        return true;
    else if(x.p*y.d==x.d*y.p && x.n < y.n)
        return true;
    else
        return false;
}

int main(){
    int m;
    int b=0;
    while(cin>>m){
        int bb=m;
        while(m--){
            if(bb!=m&&b)
                cout<<endl;
            b=1;
            int n;

            cin>>n;
            j c[n];
            for(int i=0;i<n;i++){
                cin>>c[i].d>>c[i].p;
                c[i].n=i+1;
            }
            sort(c,c+n,cmp);
            for(int i=0;i<n;i++){
                cout<<c[i].n;
                if(i!=n-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
