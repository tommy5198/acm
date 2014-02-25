#include<cstdio>

int digit[10];
int sum(){
    int mod, all = 0;
    for(int i=1; i<10; i++)
        all += digit[i] * i;
    mod = ((all-1) % 3) + 1;
    if(digit[mod] + digit[mod + 3] + digit[mod + 6] > 0)
        return digit[3] + digit[6] + digit[9] + (mod!=3);
    return 0;
}
int main(){
    int T, c;
    scanf("%d", &T);
    getchar();
    for(int t=1; t<=T; t++){
        for(int i=1; i<10; i++)
            digit[i] = 0;
        while( (c = getchar()) != '\n' && c != EOF)
            digit[c-'0']++;
        if(sum() & 1)
            printf("Case %d: S\n", t);
        else
            printf("Case %d: T\n", t);
    }
    return 0;
}
