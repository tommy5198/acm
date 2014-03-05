/*uva10106 ac
    fucking cases like "000001" ...
    rewrite
*/

#include<string>
#include<iostream>
using namespace std;


int main(){
    string a,b;
    while(cin>>a>>b){
        int t[505]={0};
        for(int i=a.size()-1;i>=0;--i)
            for(int j=b.size()-1;j>=0;--j){

                t[a.size()+b.size()-i-j-2]+=(a[i]-48)*(b[j]-48);

                if(t[a.size()+b.size()-i-j-2]>9){
                    t[a.size()+b.size()-i-j-1]+=t[a.size()+b.size()-i-j-2]/10;
                    t[a.size()+b.size()-i-j-2]%=10;
                }
            }

        if((a.size()==1&&a[0]=='0')||(b.size()==1&&b[0]=='0')){
            cout<<"0\n";
            continue;
        }
        int i;
        for(i=504 ;t[i]==0;--i);
        for(;i>=0;--i)
            cout<<t[i];
        cout<<endl;
    }
    return 0;
}
