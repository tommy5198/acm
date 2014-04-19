#include<cstdio>

char song[16][9] = {
    "Happy",
    "birthday",
    "to",
    "you",
    "Happy",
    "birthday",
    "to",
    "you",
    "Happy",
    "birthday",
    "to",
    "Rujia",
    "Happy",
    "birthday",
    "to",
    "you"
};

char person[100][101];
int main(){
    int n, p = 0, s = 0;
    bool end = false;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s", person[i]);
    while(!end)
        for(s = 0; s<16; s++){
            printf("%s: %s\n", person[p++], song[s]);
            end = p==n ? true : end;
            p = p==n ? 0 : p;
        }
    return 0;
}
