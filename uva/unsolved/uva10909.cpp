#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
/*
    freopen("WTF.txt", "w", stdout);
    vector<int> v, tmp;
    for(int i=1; i<=2000000; i+=2)
        v.push_back(i);
    printf("1");
    int k = 1;
    for(int i = v[k]; i<v.size(); i = v[k]){
        int x = 0;
        for(int j=i-1; j-x<v.size(); j+=i ){
            v.erase(v.begin()+j-x);
            x++;
        }
        k++;
    }
    printf("int num[%d] = {%d", v.size(), v[0]);
    for(int i=1; i<v.size(); i++)
       printf(", %d", v[i]);
    printf("};\n");
*/
    vector<int> v(num, num+136412);
    int n=2000000, mx =0, mxi;
    while(n){
        int i=0, j=136411;
        //j = upper_bound(v.begin(), v.end(), n) - v.begin();
       // printf("%d\n", j);
        int a = -1, b = 200000000;
        while(i<=j){
            if(v[i]+v[j] > n)
                j--;
            else if(v[i]+v[j] < n)
                i++;
            else if(v[j] - v[i] < b - a){
                a = v[i];
                b = v[j];

                i++;
                j--;
            }
        }
        if(a != -1)
            mx = max(mx, b);
        if(n%10000 == 0)
            printf("%d %d\n", n/10000, mx);
        n--;
        /*
        if(a != -1)
            printf("%d is the sum of %d and %d.\n", n, a, b);
        else
            printf("n is not the sum of two luckies!\n");*/
    }
    printf("%d", mx);
    return 0;
}