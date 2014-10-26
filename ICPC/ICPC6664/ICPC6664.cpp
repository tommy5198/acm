#include<cstdio>

int GCD(int a, int b){
    if(b==0)return a;
    return GCD(b, a%b);
}
int main(){
    int H, h, m, s;
    while(scanf("%d%d%d%d", &H, &h, &m, &s), H){
        int hv = 2, mv = 2*H, sv = 120*H;
        int hmv = H+1;
        int angs = s*120*H, angm = 2*s*H + 120*m*H, angh = 2*s+120*m+7200*h;
        int anghm = (s + s*H + 60*m + 60*m*H + 3600*h)%(3600*H);
        int tm;
        //printf("asdsadas %d %d\n", anghm, angs);
        if(angs > anghm && angs <= anghm + 3600*H){
            tm = anghm + 3600*H - angs;
            //printf("a %d\n", tm);
        }else if(angs <= anghm){
            tm = anghm - angs;
            //printf("b %d\n", tm);
        }else{
            tm = 7200*H - angs + anghm;
          //  printf("c %d\n", tm);
        }
        //printf("%d %d\n", angm*(sv-hmv)+tm*mv,  angh*(sv-hmv)+tm*hv);
        if(angm*(sv-hmv)+tm*mv == angh*(sv-hmv)+tm*hv){
            tm += 3600*H;
            //printf("d %d\n", tm);
        }
        tm += s*(sv-hmv);
        if(tm/(sv-hmv) >= 60){
            tm -= 60*(sv-hmv);
          //  printf("e %d\n", tm);
            m = m==59 ? 0 : m+1;
            h = m ? h :h==H-1?0:h+1;
        }
        int gcd = GCD(tm, sv-hmv);
        printf("%d %d %d %d\n", h, m, tm/gcd, (sv-hmv)/gcd);
    }
    return 0;
}
/*
0 0 43200 1427
0 0 4260 1427
1 56 10320 1427
1 56 6039 1427
1 56 5002 1427
3 10 12660 1427
3 10 35222 1427
7 18 28020 1427
7 18 30604 1427
7 23 27960 1427
7 23 26923 1427
0 38 1629 79
0 39 1560 79
0 39 1590 79
1 6 2260 79
1 20 1921 79
1 20 1951 79
2 15 2250 89
2 59 900 89
0 29 732 95
1 6 760 99
1 6 910 33
1 8 800 99
0 55 550 109
*/
