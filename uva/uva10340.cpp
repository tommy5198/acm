#include<iostream>
#include<string>
using namespace std;

int main(){

    string a,b;
    while(cin>>b>>a){
        int i,j=0;
        for(i=0;i<a.size()&&j<b.size();i++){
            if(a.size()-i<b.size()-j)
                break;
            if(a[i]==b[j])
                j++;
        }
        if(a.size()-i<b.size()-j){
            cout<<"No"<<endl;
            continue;
        }
        if(i==a.size()&&j!=b.size())
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;

    }
    return 0;
}
