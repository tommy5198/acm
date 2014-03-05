#include<iostream>
#include<cstdio>

using namespace std;
int k;
int used[12];
int num[12];

void btk(int x,int a){
    if(x==k&&a!=6)
        return ;
    if(a==6){

        for(int i=0;i<k;i++)
            if(used[i]){
                a--;

                printf("%d",num[i]);
                if(a)
                    printf(" ");
            }

        printf("\n");
        return ;
    }
    used[x]=1;
    btk(x+1,a+1);
    used[x]=0;
    btk(x+1,a);
}


int main()
{
    int first=0;
    while(scanf("%d",&k)!=EOF){
        if(!k)
            break;
        if(first)
            printf("\n");
        first=1;
        for(int i=0;i<k;i++){
            used[i]=0;
            scanf("%d",&num[i]);
        }
        btk(0, 0);

    }
    return 0;
}

