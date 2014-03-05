#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(!n)
            break;
        vector<int> v;
        while(n--){
            int t;
            scanf("%d",&t);
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        for(vector<int>::iterator it=v.begin();it!=v.end();it++){
            if(it!=v.begin())
                printf(" ");
            printf("%d",*it);

        }
        printf("\n");
    }
    return 0;
}
