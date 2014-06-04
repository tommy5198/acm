// kmp
#include<cstdio>

int n,cas=1;
char str[1000005];
int pi[1000005];

void prefix(){

    pi[1]=0;
    for(int i=2,j;i<=n;i++){
        for(j=i-1;j!=0 && str[pi[j]+1] != str[i];j=pi[j]);

        if(!j)
            pi[i] = 0;
        else{
            pi[i] = pi[j]+1;
            if(i % (i-pi[i]) == 0)
                printf("%d %d\n",i,i/(i-pi[i]));
        }
    }
}

int main(){

    while(scanf("%d",&n),n){
        printf("Test case #%d\n",cas);
        cas++;

        scanf("%s",str+1);
        prefix();
        printf("\n");
    }
    return 0;
}
