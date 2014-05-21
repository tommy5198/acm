// bit mask dp
#include<cstdio>
#include<cstring>
#include<algorithm>

int n, T;
int st[90];
int sc[1<<9];

bool init(){
	scanf("%d", &n);
	if(!n) return false;
	int a, b, c, s;
	memset(sc, 0, sizeof(sc));
	for(int i=0; i<n; i++){
		scanf("%d%d%d%d", &a, &b, &c, &s);
		st[i] = 1<<a-1 | 1<<b-1 | 1<<c-1;
		sc[st[i]] = s;
	}
	return true;
}

void sol(){
	for(int i=0; i<n; i++)
		for(int j=((1<<9)-1)^st[i]; j>6; j--)
			if(sc[j] && !(j&st[i]))
				sc[j|st[i]] = std::max(sc[j|st[i]], sc[j]+sc[st[i]]);
			
	if(!sc[(1<<9)-1])
		printf("Case %d: -1\n", T++);
	else
		printf("Case %d: %d\n", T++, sc[(1<<9)-1]);
}

int main(){
	T = 1;
	while(init())
		sol();
	
	return 0;	
}
