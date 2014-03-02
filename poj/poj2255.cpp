//recursive
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
map<char, int> m;
char str[2][27];

void post(int st1, int ed1, int st2, int ed2){
    int root = m[str[0][st1]];

    if(root != st2)
        post(st1+1, st1+root-st2, st2, root-1);
    if(root != ed2)
        post(st1+root-st2+1, ed1, root+1, ed2);
    printf("%c", str[0][st1]);
}
int main(){

    char c;
    while(scanf("%s%s", str[0], str[1]) != EOF){
        for(int i=0; str[1][i]; i++)
            m[str[1][i]] = i;
        post(0, strlen(str[0])-1, 0, strlen(str[0])-1);
        printf("\n");
    }
    return 0;
}
