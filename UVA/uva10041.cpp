#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;


int main(){
    int n;
    while(cin>>n){
        while(n--){
            int t;
            cin>>t;
            int i,num[t];
            for(i=0;i<t;i++)
                cin>>num[i];
            sort(num,num+i);
            int j=num[i/2],sum=0;
            for(i=0;i<t;i++)
                sum+=abs(num[i]-j);
            cout<<sum<<endl;
        }
    }
    return 0;
}
