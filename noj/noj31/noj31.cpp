#include<cstdio>

int main()
{
    char a[101], b[101];
    while(scanf("%s%s", a, b) != EOF) {
        int LCS[101][101] = {{0}};
        int i, j;
        for(i=1; a[i-1]; i++)
            for(j=1; b[j-1]; j++)
                if(a[i-1] == b[j-1])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = LCS[i-1][j]>LCS[i][j-1] ? LCS[i-1][j] : LCS[i][j-1];
        printf("%d\n", LCS[i-1][j-1]);
    }
    return 0;
}
