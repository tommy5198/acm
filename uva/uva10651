// bit mask dp
#include<cstdio>
#include<algorithm>

int bsm, st[1<<12];

void bt(int bit, int bno, int bcnt){
	if(!bcnt){
		int msk;
		st[bit] = st[bit] ? st[bit] : bsm;
		for(int i=0; i<10; i++){
			if( !(bit&1<<i+1) && !(bit&1<<i+2) && bit&1<<i )
				st[bit ^ (1<<i | 1<<i+1 | 1<<i+2)] = st[bit ^ (1<<i | 1<<i+1 | 1<<i+2)] ? std::min(st[bit ^ (1<<i | 1<<i+1 | 1<<i+2)], st[bit]) : st[bit];
			if( !(bit&1<<10-i) && !(bit&1<<9-i) && bit&1<<11-i )
				st[bit ^ (1<<11-i | 1<<10-i | 1<<9-i)] = st[bit ^ (1<<11-i | 1<<10-i | 1<<9-i)] ? std::min(st[bit ^ (1<<11-i | 1<<10-i | 1<<9-i)], st[bit]) : st[bit];
		}
		
		return ;
	}	
	if(bno == 12) return ;
	bt(bit|1<<bno, bno+1, bcnt-1);
	bt(bit, bno+1, bcnt);
}

void init(){
	for(bsm=0; bsm<=12; bsm++)
		bt(0, 0, bsm);
}

int main(){
	int n, bit;
	
	init();
	scanf("%d", &n);
	while(n--){
		bit = 0;
		getchar();
		for(int i=0; i<12; i++)
			if(getchar() == 'o')
				bit |= 1<<i;
		printf("%d\n", st[bit]);
	}
	return 0;
}


