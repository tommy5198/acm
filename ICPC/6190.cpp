#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int W, N, a[50005], min, remain, line, num;
    while(scanf("%d%d", &W, &N))
    {
        if(W == 0 && N == 0)
            break;
        memset(a, 0, sizeof(a));
        min = 80005;
        line = num = 0;
        remain = W;
        for(int i=0; i<N; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] + num*1 <= remain)
            {
                remain -= a[i];
                num++;
            }
            else
            {
                printf("A>%d %d %d\n", i, remain, num);
                line++;
                if(num==2)
                {
                    if(remain < min)
                        min = remain;
                }
                else
                {
                    if(remain%num)
                    {
                        if((int)remain/num + 1 < min)
                            min = (int)remain/num + 1;
                    }
                    else
                    {
                        if(remain/num < min)
                            min = remain/num;
                    }
                }
                num = 1;
                remain = W - a[i];
            }
        }
        if(line == 0)
            printf("1\n");
        else
            printf("%d\n", min);
    }
    return 0;
}
