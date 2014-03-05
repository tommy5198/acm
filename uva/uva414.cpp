#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(!n) break;
        int ans=0,i=n,Max=0,X[13]={0};
        string t;
        getchar();
        while(i--){
            int tmp=0;

            getline(cin,t);

            for(int j=0;j<t.size();j++)
                if(t[j]=='X')
                    tmp++;
            if(Max<tmp)
                Max=tmp;
            X[i]=tmp;

        }
        for(int i=0;i<n;i++)
            ans+=Max-X[i];
        cout<<ans<<endl;
    }
    return 0;
}
