#include<cstdio>

int main()
{
	int n, m;
	int L = 0, R = 0;
	int a[100000];
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", a+i);
		L = L > a[i] ? L : a[i];
		R += a[i];
	}

	while(L < R) {
		int mid = (L+R) / 2;
		int sum = a[0], cnt = 1;
		for(int i=0; i<n-1; i++)
			if(sum + a[i+1] > mid)
				cnt++, sum = a[i+1];
			else
				sum += a[i+1];
		if(cnt <= m)
			R = mid;
		else
			L = mid + 1;
	}
	printf("%d\n", R);
	return 0;
}
