#include<cstdio>

int f(int a, int b)
{
	if(a < 0) return 0;
	if(b == 1) return 1;
	return f(a-b, b) + f(a, b-1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", f(n, m));
	}
	return 0;
}
