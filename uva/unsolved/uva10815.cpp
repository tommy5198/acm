//string mapping
#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;

bool isA(int c){
    return c>='A' && c<='Z';
}
bool isa(int c){
    return c>='a' && c<='z';
}
int main(){
    map<string, bool> word;
    map<string, bool>::iterator itr;
    int c, top = 0;
    string str;
    while( (c = getchar()) != EOF){
        if(!str.empty() && !isA(c) && !isa(c)){
            word[str] = true;
            str.clear();
        }else if(isA(c)){
            c += 'a' - 'A';
            str.push_back(c);
        }else if(isa(c))
            str.push_back(c);
    }
    for(itr = word.begin(); itr != word.end(); ++itr)
        puts(itr->first.c_str());
    return 0;
}
