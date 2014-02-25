#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[100005],rstr[100005];
int p[100005], len;

void prefix(){
    int j = 0;
    for(int i=2; i<=len; i++){

        while(j > 0 && rstr[j + 1]!=rstr[i])
            j = p[j];
        if(rstr[j + 1] == rstr[i])
            j++;
        p[i] = j;

    }

}
int kmp(){

    int R = 0, q = 0;
    len = strlen(str+1);
    for(int i=0; i<len; i++)
        rstr[i + 1] = str[len - i];
    rstr[len + 1] = '\0';
    prefix();

    for(int i=1; i<=len; i++){
        while(q > 0 && rstr[q + 1]!=str[i]){
            R += q-p[q];
            q = p[q];
        }
        if(rstr[q + 1] == str[i])
            q++;
        if(q == 1)
            R = i;
    }
    return len - R + 1;
}

int main(){

    while(scanf("%s", str+1) != EOF)
        printf("%s%s\n", str+1, rstr + 1 + kmp());
    return 0;
}
