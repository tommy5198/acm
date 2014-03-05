#include<iostream>
#include<cstdio>
#include <sstream>
using namespace std;

int main(){

    string str[2];
    while(getline(cin,str[0])){
        getline(cin,str[1]);

        int a[100],b[100],al=0,bl=0,match=0;
        stringstream s1(str[0]);
        stringstream s2(str[1]);

        while(s1>>a[al])
            al++;
        while(s2>>b[bl])
            bl++;

        for(int i=0;i<al;i++)
            for(int j=0;j<bl;j++)
                if(a[i]==b[j]){
                    match++;
                    break;
                }
        if(match==al || match==bl){
            if(al==bl)
                cout<<"A equals B"<<endl;
            else if(al>bl)
                cout<<"B is a proper subset of A"<<endl;
            else
                cout<<"A is a proper subset of B"<<endl;
        }else if(match)
            cout<<"I'm confused!"<<endl;
        else
            cout<<"A and B are disjoint"<<endl;


    }
    return 0;
}
