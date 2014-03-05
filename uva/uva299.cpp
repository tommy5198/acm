/*AC 0.008ms 2012/9/22*/

#include<iostream>

using namespace std;

int main(){
	
	int N;
	
	while(cin >> N){
		
		while(N--){
			
			int L,tl,ans=0;
			int tmp[50]={0},num[50];
			
			cin>>tl;
			L=tl;
			while(tl--)
				cin >> num[L-tl-1];
			
			for(int i=1; i<=L ;++i)
				for(int j=0;j<L;++j)
					if(num[j]==i){
					
						for(int x=j;x>i-1;--x)
						{
							int t=num[x];
							num[x]=num[x-1];
							num[x-1]=t;
							ans++;
						}
						break;
					}
			cout<<"Optimal train swapping takes "<<ans<<" swaps.\n";
			
		}
	}
	return 0;
}
