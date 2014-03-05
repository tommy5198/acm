#include<cstdio> 
#include<cstdlib>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		bool isUsed[3000] = {false};
		bool fail = false;
		int prev;
		scanf("%d",&prev);
		for(int i = 1; i < n; i++){
			int t;
			scanf("%d",&t);
			if(abs(prev-t) > n-1 || prev == t || isUsed[abs(prev-t)]){
				fail = true;
			}else{
				isUsed[abs(prev-t)] = true;
			}
			prev = t;
		}
		if(fail){
			printf("Not jolly\n");
		}else{
			printf("Jolly\n");
		}
	} 
	return 0;
}
				
			
