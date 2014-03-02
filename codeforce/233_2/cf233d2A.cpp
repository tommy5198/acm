#include<iostream>
using namespace std;

int main(){
    int n, p, k, st;
    cin>>n>>p>>k;
    st = p-k;
    if(st > 1)
        cout<<"<< ";
    else
        st = 1;
    for(; st<p; st++)
        cout<<st<<" ";
    cout<<"("<<p<<")";
    st++;
    for(; st <= p+k && st <= n; st++)
        cout<<" "<<st;
    if(st != n+1)
        cout<<" >>";
    return 0;
}
