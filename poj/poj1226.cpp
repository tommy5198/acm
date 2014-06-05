// substr match
#include<cstdio>
#include<cstring>

int n, len;
char str[100][105];

void init(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s", str[i]);
    len = strlen(str[0]);
}

void sol(){
    char rstr[105];    
    for(int i=0; i<len; i++){
        for(int j=0; j<=i; j++){
            int pre = str[0][j+len-i];
            bool end = false;
            
            for(int k=0; k<len-i; k++)
                rstr[k] = str[0][j+len-i-k-1];
            str[0][j+len-i] = rstr[len-i] = 0;
            
            for(int k=1; k<n && !end; k++)
                if(!strstr(str[k], str[0]+j) && !strstr(str[k], rstr))
                    end = true;
            
            if(!end){
                printf("%d\n", len-i);
                return ;
            }
            
            str[0][j+len-i] = pre;
        }
    }
    puts("0");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        sol();
    }
    return 0;
}
