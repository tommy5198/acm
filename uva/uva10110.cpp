#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;

int main(){
    unsigned int n;
    std::ios_base::sync_with_stdio(false);
    while(cin>>n){
        if(!n)
            break;
        unsigned int t=sqrt(n);
        if(n==t*t)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
