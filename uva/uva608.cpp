#include<iostream>
using namespace std;


int main(){

    int n;
    while(cin>>n){
        while(n--){
            string l,r,b;
            int sp[100]={0};
            for(int i=0;i<3;i++){
                cin>>l>>r>>b;

                if(b=="even")
                    for(int j=0;j<l.size();j++){
                        sp[l[j]]=2;
                        sp[r[j]]=2;
                    }
                else if(b=="up")
                    for(char j=65;j<77;j++){
                        int t=0;
                        for(int x=0;x<l.size();x++){
                            if(j==l[x] && sp[j]!=2 && sp[j]!=1){
                                t=1;
                                sp[j]=-1;
                            }else if(j==r[x] && sp[j]!=2 && sp[j]!=-1){
                                sp[j]=1;
                                t=1;
                            }
                        }
                        if(!t)
                            sp[j]=2;
                    }
                else if(b=="down")
                    for(char j=65;j<77;j++){
                        int t=0;
                        for(int x=0;x<l.size();x++){
                            if(j==l[x] && sp[j]!=2 && sp[j]!=-1){
                                t=1;
                                sp[j]=1;
                            }else if(j==r[x] && sp[j]!=2 && sp[j]!=1){
                                sp[j]=-1;
                                t=1;
                            }
                        }
                        if(!t)
                            sp[j]=2;
                    }
            }
            int li=0,hv=0;
            char L,H;
            for(int i=65;i<77;i++){
                if(sp[i]==-1){
                    hv++;
                    H=i;

                }else if(sp[i]==1){
                    li++;
                    L=i;

                }
            }

            if(li==1)
                cout<<L<<" is the counterfeit coin and it is light."<<endl;
            else if(hv==1)
                cout<<H<<" is the counterfeit coin and it is heavy."<<endl;
        }
    }
    return 0;
}
