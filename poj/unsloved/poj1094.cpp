#include<cstdio>

int c[27][27];

bool topsort(){
    

}

int main(){

    int n, m;
    while(scanf("%d%d", &n, &m), n&&m){
        char a, b;
        bool fail = false;
        for(int i=0; i<m; i++){
            getchar();
            a = getchar();
            getchar();
            b = getchar();
            c[a-'A'][b-'A'] = 1;
            if(topsort())
                fail = true;
        }
        if(fail)
            printf()
    }
    return 0;
}
