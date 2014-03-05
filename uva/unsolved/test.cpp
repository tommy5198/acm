#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct ker{
    int val, mx;
    vector <pair<int,int> > v;
    bool operator < (ker a) const{
        return a.val < val;  // < is min heap;
    }
}tmp,now;
int a[100][2000],p[100];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int T,N,M,i,j;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &M, &N);
        now.val = now.mx = 0;
        now.v.clear();
        for(i=0;i<M;i++){
            for(j=0;j<N;j++)
                scanf(" %d",&a[i][j]);
            sort(a[i],a[i]+N);
            now.val += a[i][0];
        }
        priority_queue <ker> q;
        q.push(now);
        int n = N,re = 0;
        while(n--){
            int mini = 1e9,which = -1;
            now = q.top();    q.pop();

                printf("%d",now.val);
            if(n)
                printf(" ");
            for(i=0;i<M;i++)
                p[i] = 1;
            for(i=0;i<now.v.size();i++)
                p[now.v[i].first] = now.v[i].second;

            for(i=now.mx;i<M;i++){
                tmp = now;
                tmp.val = tmp.val-a[i][p[i]-1]+a[i][p[i]];
                tmp.mx = max(tmp.mx, i);
                //printf("tmp = %d\n",tmp.val);
                int ok = 0;
                for(j=0;j<tmp.v.size();j++)
                    if(tmp.v[j].first==i){
                        ok = 1;
                        tmp.v[j].second++;
                    }
                if(ok==0){
                    tmp.v.push_back(make_pair(i,2));
                }
                q.push(tmp);
            }
        }
        printf("\n");
    }

    return 0;
}
