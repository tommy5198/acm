#include<iostream>
#include<string>
using namespace std;

int main(){

    string t;

    while(getline(cin,t)){
        int flag=0;

        for(int i=0;i<t.size();i++)
            if(t[i]==' ' || t[i+1]=='\0'){
                if(t[i+1]=='\0')
                    i++;
                for(int j=i-1;j>=flag;j--)
                    cout<<t[j];
                if(t[i]!='\0')
                    cout<<" ";
                flag=i+1;
            }
        cout<<endl;

    }
    return 0;
}
