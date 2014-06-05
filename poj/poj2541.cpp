// kmp
#include<cstdio>

int n, m, sub, st;
char str[1001005];
char pof[15];
int p[15];

void prefix(char *pstr){
    
    for(int i=2, j=0; pstr[i]; i++){
        while(j > 0 && pstr[j+1] != pstr[i])
            j = p[j];
        if(pstr[j+1] == pstr[i])
            j++;
        p[i] = j;
    }
}

char kmp(int tail){
    int ans = 0; 
    sub = tail<13 ? 13-tail : 0;
    for(int i=13, j=tail; i>=sub; i--, j--)
        pof[i+1] = str[j];
    
    for(int i=sub; i<13 && !ans; i++){
        prefix(pof+i);

        for(int j=st, k=0; j<tail-1; j++){
            while(k > 0 && pof[i+k+1] != str[j])
                k = p[k];
            if(pof[i+k+1] == str[j])
                k++;
            if(i+k+1 == 14){
                ans = str[j+1];

                // optimize
                st = i ? j+1-(13-i) : j+1-(13-i)+1;
                k = p[k];
            }
        }

    }
    return ans ? ans : '0';
}

int main(){
    scanf("%d%d%s", &n, &m, str);
    
    for(int i=0; i<m; i++)
        printf("%c", str[n+i]=kmp(n+i));
    puts("");
    
    return 0;
}
