#include<cstdio>
#include<cstring>

int main(){
    int T;
    scanf("%d", &T);
    getchar();
    while(T--) {
        int sum = 0;
        int cnt[26] = {0};
        for(char c; (c=getchar()) != '\n' && c; sum++) {
            cnt[c - 'a']++;
        }
        int i;
        for(i=0; i<26; i++)
            if(sum == cnt[i]*2) break;
        if(i != 26)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
