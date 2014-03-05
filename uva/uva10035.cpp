#include<iostream>
using namespace std;

int main(){
    long long int a,b;
    while(cin>>a>>b){
        if(!a&&!b)
            break;
        int carry=0,c=0;
        while(a&&b){
            if(c+a%10+b%10>9){
                carry++;
                c=1;
            }else
                c=0;
            a/=10;
            b/=10;
        }
        while(a%10+c>9||b%10+c>9){
            carry++;
            a/=10;
            b/=10;
        }
        if(carry>1)
            cout<<carry<<" carry operations."<<endl;
        else if(carry==1)
            cout<<carry<<" carry operation."<<endl;
        else
            cout<<"No carry operation."<<endl;
    }
    return 0;
}

