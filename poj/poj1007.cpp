#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct DNA{
    int ori,inv;
    string str;
    bool operator<(const struct DNA &t)const{
        if(inv==t.inv)
            return ori<t.ori;
        return inv<t.inv;
    }
}dna[101];

int main(){

    
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>dna[i].str;
            dna[i].ori=i;
            dna[i].inv=0;
            for(int x=0;x<dna[i].str.size();x++)
                for(int y=x+1;y<dna[i].str.size();y++)
                    if(dna[i].str[x]>dna[i].str[y])
                        dna[i].inv++;
        }
        sort(dna,dna+m);
        for(int i=0;i<m;i++)
            cout<<dna[i].str<<endl;
        
            cout<<endl;
    
    return 0;
}