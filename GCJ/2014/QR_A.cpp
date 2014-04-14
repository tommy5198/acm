#include<cstdio>

int main(){

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        int ans, grid[4][4];
        int first[4];
        int ANS = 0;
        scanf("%d", &ans);
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                scanf("%d", grid[i]+j);
        for(int i=0; i<4; i++)
            first[i] = grid[ans-1][i];
        scanf("%d", &ans);
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                scanf("%d", grid[i]+j);
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                if(first[j] == grid[ans-1][i])
                    if(ANS) ANS = -1;
                    else ANS = first[j];
        if(ANS > 0)
            printf("Case #%d: %d\n", t, ANS);
        else if(ANS == 0)
            printf("Case #%d: Volunteer cheated!\n", t);
        else
            printf("Case #%d: Bad magician!\n", t);
    }
    return 0;
}
