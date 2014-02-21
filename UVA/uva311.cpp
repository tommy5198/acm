#include<iostream>

using namespace std;

int main(){

    int n[6];
    while(cin>>n[0]>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]){
        if(n[0]+n[1]+n[2]+n[3]+n[4]+n[5]==0)
            break;
        int ans=0;
        ans+=n[5]+n[4]+n[3]+n[2]/4;
        n[2]%=4;
        for(int i=0;i<n[4];i++){
            if(n[0]>=11)
                n[0]-=11;
            else {
                n[0]=0;
                break;
            }
        }

        for(int i=0;i<n[3];i++){
            if(n[1]>=5)
                n[1]-=5;
            else{
                if(n[0]>=20-4*n[1]){
                    n[0]-=20-4*n[1];
                    n[1]=0;
                }else{
                    n[0]=0;
                    n[1]=0;
                    break;
                }

            }
        }

        if(n[2]){
            ans++;
            if(n[1]>=(3-n[2])*2+1){
                n[1]-=(3-n[2])*2+1;
                if(n[0]>=36-n[2]*9-4*(3-n[2])*2-4)
                    n[0]-=36-n[2]*9-4*(3-n[2])*2-4;
                else
                    n[0]=0;
            }
            else{
                if(n[0]>=36-n[1]*4-9*n[2])
                    n[0]-=36-n[1]*4-9*n[2];
                else
                    n[0]=0;
                n[1]=0;
            }
        }
        ans+=n[1]/9;
        n[1]%=9;
        if(n[1]){
            ans++;
            if(n[0]>=36-n[1]*4)
                n[0]-=36-n[1]*4;
            else
                n[0]=0;
        }
        ans+=n[0]/36;
        n[0]%=36;
        if(n[0])
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}




