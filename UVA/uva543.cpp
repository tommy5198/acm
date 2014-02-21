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
    int n;
    while(cin>>n){
        if(!n)
            break;
        int i;
        for(i=2;i<1000000;i++){
            if(isprime(i)&&isprime(n-i))
                break;
        }
        cout<<n<<" = "<<i<<" + "<<n-i<<endl;
    }
    return 0;
}
