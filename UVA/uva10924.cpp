#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;

bool isprime(int t){
    if(t==2||t==3)
        return true;
    else if(t%2==0||t%3==0)
        return false;
    int s=sqrt(t);
    for(int i=2;i<=s;i++)
        if(t%i==0)
            return false;
    return true;
}

int main(){
    string n;
    while(cin>>n){
        int num=0;
        for(int i=0;i<n.size();i++)
            if(isalpha(n[i])){
                if(islower(n[i]))
                  num+=n[i]-97+1;
                else
                    num+=n[i]-65+27;
            }
        if(isprime(num))
            cout<<"It is a prime word."<<endl;
        else
            cout<<"It is not a prime word."<<endl;
    }
    return 0;
}
