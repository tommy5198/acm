//dont use MTFr string
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int i, m=-1, cnt=0;
    string str[101];
    for(i=0; getline(cin, str[i]) ; i++)
        m = max(m, (int)str[i].size());
    for(int j = 0; j<m; j++){
        cnt = 0;
        for(int k=i; k>=0; k--){
            if(j < str[k].size())
                cout<<str[k][j];
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
