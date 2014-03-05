#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){

	int N;
	cin>>N;

	for(int c=1;c<=N;c++){

		int n,e=1,co=0;
		int d[101][101];
		int b[101][101];
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		
		cin>>n;
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++){
				scanf("%d",&d[j][i]);
				d[i][j]=d[j][i];
			}

		for(int k=1;k<=n&&b;k++)
			for(int i=1;i<=n&&b;i++)
				for(int j=1;j<=n&&b;j++){
					if(i==k||i==j||j==k)
						continue;
					else if(d[i][k]+d[k][j]<d[i][j])
						e=0;
					else if(!b[i][j] && d[i][k]+d[k][j]==d[i][j]){
						b[i][j]=1;
						b[j][i]=1;
					}
				}
		
		cout<<"Case #"<<c<<":"<<endl;
		if(!e)
			cout<<"Need better measurements."<<endl;
		else{
			
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(i!=j && !b[i][j])
						co++;
			cout<<co<<endl;
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(i!=j && !b[i][j])
						printf("%d %d %d\n",i,j,d[i][j]);
		}
			cout<<endl;
	}
	return 0;
}

					
					
