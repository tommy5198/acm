// prefix
#include<cstdio>
#include<cstring>
char str[1000001];
int pi[1000005];

int main(){

    while(1){
        scanf("%s",str);
        if(str[0] == '.' && str[1] == '\0')
            break;
        int l=strlen(str);
        int q=-1;
        pi[0]=-1;
        for(int i=1;i<l;i++){
            while(q > -1 && str[q+1] != str[i])
                q = pi[q];
            if(str[q+1] == str[i])
                q++;
            pi[i] = q;
        }
        int i;
        int sl=l-1-pi[l-1];
        for(i=l-1;i>=0;i=pi[i]){
            if(sl != i-pi[i])
                break;
        }

        if(i != -1)
            printf("1\n");
        else
            printf("%d\n",l/sl);
    }
    return 0;
}
