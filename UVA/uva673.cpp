#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char p[200];
    int len, n, j;
    scanf("%d", &n);
    getchar();
    while(n--){
        gets(p);
        len = strlen(p);
        for(int i=0; i<len; i++){
            if(p[i] == ' ')   // god damn ' '
                continue;
            if(p[i] == ')'){
                for(j = i-1; j >= 0 && p[j] == ' '; j--) ;
                if(j < 0 || p[j] != '(')
                    break;
                p[i] = p[j] = ' ';
            }else if(p[i] == ']'){
                for(j = i-1; j >= 0 && p[j] == ' '; j--) ;
                if(j < 0 || p[j] != '[')
                    break;
                p[i] = p[j] = ' ';
            }

        }
        for(j=0; j<len && p[j] == ' '; j++) ;
        if(j == len)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
