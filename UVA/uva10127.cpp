#include<iostream>

using namespace std;

int main(){

    int n;
    while(cin>>n){
        int ones=1%n;
        int count=1;
        while(ones){
            ones=ones*10+1;
            ones%=n;
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}

