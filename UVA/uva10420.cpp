#include<string>
#include<iostream>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n){
		int N=n,count[2000]={0};
		string ans[2000];
		while(n--){
			
			string c,t;
			cin>>c;
			getline(cin,t);
			for(int i=0;i<N;++i){
				if(ans[i]!=c){
					ans[i]=c;
					count[i]++;
				}
			}	
			
		}
	}
	return 0;
}
