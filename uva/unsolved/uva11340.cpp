#include<cstdio>

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		double price[256] = {0.0};
		char c[2];
		int k;
		double sum = 0.0;
		scanf("%d",&k);
		while(k--){
			scanf("%s", c);
			scanf("%lf", &price[c[0]]);
		}
		scanf("%d",&k);
		gets(c);
		while(k--){
			char str[10002];
			gets(str);
			for(int i=0; str[i]; i++){
				sum += price[str[i]];
			}
			//printf("%d\n",k);
		}
		sum/=100;
		
		printf("%.2lf$\n",(double)sum/100.0);
	}
	scanf(" ");
	return 0;
}
