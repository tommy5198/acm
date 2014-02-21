#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    double n, p;
    while(cin>>n>>p)
        printf("%.0f\n", pow(p, 1/n));
    return 0;
}
