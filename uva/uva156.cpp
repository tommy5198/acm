//sort
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool mode;

struct Str{
    char ostr[21];
    char str[21];
    bool operator<(const Str &t)const{
        if(mode){
            if(strcmp(ostr, t.ostr) < 0)
            return true;
        else
            return false;
        }
        if(strcmp(str, t.str) < 0)
            return true;
        else
            return false;
    }
};

int main(){

   vector<Str> v, ans;
    Str str;
    mode = false;
    while(scanf("%s", str.ostr) != EOF){
        if(str.ostr[0] == '#')
            break;
        strcpy(str.str, str.ostr);

        int len = strlen(str.str);
        for(int i=0; i<len; i++)
            if(str.str[i] >= 'a')
                str.str[i] -= 'a' - 'A';
        sort(str.str, str.str+len);
        v.push_back(str);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size() - 1;i++){
            //cout<<v[i].str<<endl;
        int j=i;
        while(i<v.size()-1 && !strcmp(v[i].str, v[i+1].str))
            i++;
        if(j == i){
           ans.push_back(v[i]);
            if(i == v.size()-2)
                ans.push_back(v[i+1]);
        }
    }
    mode = true;
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i].ostr<<endl;
    return 0;
}
