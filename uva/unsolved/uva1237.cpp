#include<cstdio>

struct Car{
	char name[21];
	int h,l;
	bool in(int p){
		return p<=h && p>=l;
	}
}car[10000];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int d,q;
		
		scanf("%d",&d);
		for(int i=0;i<d;i++){
			scanf("%s %d %d",&car[i].name, &car[i].l, &car[i].h);
		}
		scanf("%d",&q);
		while(q--){
			int price;
			int Det = -1;
			scanf("%d",&price);
			for(int i=0; i<d; i++){
				if(car[i].in(price)){
					if(Det != -1){
						Det = -1;
						break;
					}
					Det = i;
				}
			}
			if(Det != -1){
				printf("%s\n", car[Det].name);
			}else{
				printf("UNDETERMINED\n");
			}
		}
		if(T)
		printf("\n");
	}
	
	return 0;
}
		
