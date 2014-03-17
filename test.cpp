/*
	POJ 1703 http://poj.org/problem?id=1703
*/
#include<cstdio>
#define MAXSIZE 100009
//#define TEST
int Boss[MAXSIZE], Opposite[MAXSIZE], Member[MAXSIZE];

int FindBoss(int x){
	if(Boss[x]==x){
		return x;
	}
	return Boss[x] = FindBoss(Boss[x]);
}
void MergeGroup(int a, int b){
	a = FindBoss(a);
	b = FindBoss(b);
	if(a==b){return;}
	if(Member[a]<=Member[b]){
		Boss[a] = b;
		Member[b] += Member[a];
	}else{
		Boss[b] = a;
		Member[a] += Member[b];
	}
}
int CompareTwo(int a, int b){
	a = FindBoss(a);
	b = FindBoss(b);
	if(a==b){
		//the same boss
		return 3;
	}
	if(Opposite[a]==Opposite[b]){
		//the same enemy, we are friends
		MergeGroup(a,b);
		return 3;
	}
	if(Opposite[a]==b || Opposite[b]==a){
		//I am your enemy
		return 2;
	}
	return 1;

}
void fun_A(int a, int b){
	int x=CompareTwo(a,b);
	switch(x){
	case 1:
		printf("Not sure yet.\n");
		break;
	case 2:
		printf("In different gangs.\n");
		break;
	case 3:
		printf("In the same gang.\n");
		break;
	}
}
void fun_D(int a, int b){
	Boss[a] = FindBoss(a);
	Boss[b] = FindBoss(b);
	Opposite[ Boss[a] ] = Boss[b];
	Opposite[ Boss[b] ] = Boss[a];
	if(a==Boss[a] && Member[a]==0)Member[a]=1;
	if(a==Boss[b] && Member[b]==0)Member[b]=1;
}
void ResetBoss(int n){
	for(int i=0; i<=n; i++){
		Opposite[i] = Boss[i] = i; //I am me.
		Member[i] = 0;
	}
}
int main(){
#ifdef TEST
	freopen("poj1703.txt", "r", stdin);
#endif // TEST
	int CASE, n, m, i, a, b;
	char str[5];
	scanf("%d", &CASE);
	while(CASE--){
		scanf("%d%d", &n, &m);
		ResetBoss(n);
		for(i=0; i<m; i++){
			scanf("%s%d%d", str, &a, &b);
			if(str[0]=='A'){
				fun_A(a,b);
			}else if(str[0]=='D'){
				fun_D(a,b);
			}
		}
	}
	return 0;
}
