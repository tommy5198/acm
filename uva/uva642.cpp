#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;

int main(){
    string tmp, str;
    map<string, set<string> > m;
    set<string>::iterator itr;
    while(cin >> tmp){
        if(tmp == "XXXXXX")
            break;
        str = tmp;
        sort(tmp.begin(), tmp.end());
        m[tmp].insert(str);
    }
    while(cin>>tmp){
         if(tmp == "XXXXXX")
            break;
        sort(tmp.begin(), tmp.end());
        if(!m[tmp].empty())
            for(itr = m[tmp].begin(); itr != m[tmp].end(); ++itr)
                cout<<*itr<<endl;
        else
            cout<<"NOT A VALID WORD"<<endl;
        cout<<"******"<<endl;
    }
    return 0;
}
