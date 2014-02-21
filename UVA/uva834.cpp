#include<iostream>
#define s(a,b) {int t=(a); (a)=(b); (b)=t;}
using namespace std;

int main(){

    int a,b;
    while(cin>>a>>b){
        cout<<"["<<a/b<<";";
        a=a%b;
        s(a,b);
        while(a%b){
            cout<<a/b<<",";
            a=a%b;
            s(a,b);

        }
        cout<<a/b<<"]"<<endl;
    }
    return 0;
}
