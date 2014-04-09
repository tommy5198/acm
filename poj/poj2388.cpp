#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> v;
        while(n--){
            int t;
            cin>>t;
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        int middle=v.size()/2;
        cout<<v[middle]<<endl;
    }
    return 0;
}