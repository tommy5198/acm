// cut vertex
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

int n, m, T, cnt, dpt;
int ep[100], dfn[100], low[100];
char str[100][31], ans[100][31];
int e[100][100];
map<string, int> mp;

int cmp(const void *a, const void *b){
	return strcmp((const char*)a, (const char*)b);
}

bool init(){
	scanf("%d", &n);
	if(!n) return false;
	
	char a[31], b[31];
	int ai, bi;
	mp.clear();
	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
		mp[string(str[i])] = i;
		ep[i] = dfn[i] = low[i] = 0;
	}
	
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%s%s", a, b);
		ai = mp[string(a)];
		bi = mp[string(b)];
		e[ai][ep[ai]++] = bi;
		e[bi][ep[bi]++] = ai;
	}
	dpt = cnt = 0;
	return true;
}

void dfs(int nw, int p){
	int kid = 0;
	bool cut = false;
	dfn[nw] = low[nw] = ++dpt;
	for(int i=0; i<ep[nw]; i++){
		int nt = e[nw][i];
		if(!dfn[nt]){
			dfs(nt, nw);
			kid++;
			if(dfn[nw]<=low[nt]) cut=true;
			low[nw] = low[nw] < low[nt] ? low[nw] : low[nt];
		}else if(nt != p)
			low[nw] = low[nw] < dfn[nt] ? low[nw] : dfn[nt];
	}
	if((kid>1||p!=-1) && cut) strcpy(ans[cnt++], str[nw]);
}

void sol(){
	for(int i=0; i<n; i++)
		if(!dfn[i])
			dfs(i, -1);
	if(T) puts("");
	printf("City map #%d: %d camera(s) found\n", ++T, cnt);
	qsort(ans, cnt, sizeof(char)*31, cmp);
	for(int i=0; i<cnt; i++)
		puts(ans[i]);
}

int main(){
	T = 0;
	while(init())
		sol();
	return 0;
}
