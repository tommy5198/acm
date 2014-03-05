#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n,m,c;
    int seq=1;
    while(cin>>n>>m>>c && n && m && c){
        int cap[21]={0};
        int on[21]={0};
        int mx=0,cur=0;
        for(int i=0;i<n;i++)
            cin>>cap[i];
        while(m--){
            int t;
            cin>>t;
            t--;
            if(on[t]){
                on[t]=0;
                cur-=cap[t];

            }else{
                on[t]=1;

                cur+=cap[t];

                mx=max(cur,mx);
            }

        }
        cout<<"Sequence "<<seq<<endl;
        seq++;
        if(mx>c)
            cout<<"Fuse was blown."<<endl;
        else
            cout<<"Fuse was not blown."<<endl<<"Maximal power consumption was "<<mx<<" amperes."<<endl;
        cout<<endl;
    }
    return 0;
}
