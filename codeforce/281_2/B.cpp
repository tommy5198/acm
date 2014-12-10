#include<cstdio>

int main(){
    int n, bgr = -1, last = 0, i = 0, j = 0;
    int point[2][200001];
    long long sum[2] = {0, 0};
    scanf("%d", &n);
    while(n--){
        int num;
        scanf("%d", &num);
        if(num>0){
            point[0][i++] = num;
            if(bgr==-1 && point[1][i-1]){

                if(point[1][i-1] < point[0][i-1])
                    bgr = 0;
                else if(point[1][i-1] > point[0][i-1])
                    bgr = 1;
            }
            sum[0] += num;
            last = 0;
        }else{
            point[1][j++] = -num;
            if(bgr==-1 && point[0][j-1]){

                if(point[1][j-1] < point[0][j-1])
                    bgr = 0;
                else if(point[1][j-1] > point[0][j-1])
                    bgr = 1;
            }
            sum[1] -= num;
            last = 1;
        }
       
    }
    if(sum[0] > sum[1])
        puts("first");
    else if(sum[0] < sum[1])
        puts("second");
    else{
        if(!bgr)
            puts("first");
        else if(bgr == 1)
            puts("second");
        else{
            if(i > j)
                puts("first");
            else if(i < j)
                puts("second");
            else if(!last)
                puts("first");
            else
                puts("second");
        }
    }
    return 0;
}
