#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;


int main(){

    int n;
    vector<char*> str;
    while(cin>>n){
        int a,b=n+1,i=0;
        double tmp;
        char tt[101][100];
        while(b<=2*n){
            tmp=(double)(n*b)/(b-n);
            a=tmp;
            if(tmp==(double)a){
                
                sprintf(tt[i],"1/%d = 1/%d + 1/%d",n,a,b);
                i++;
            }
            b++;
        }
        cout<<i<<endl;
        for(int j=0;j<i;j++)
            cout<<tt[j]<<endl;
        str.clear();
    }
}
