#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    if(!n){
        puts("O-|-OOOO");
        return 0;
    }
    while(n){
        switch(n%10){
            case 0:
                puts("O-|-OOOO");
            break;
            case 1:
                puts("O-|O-OOO");
            break;
            case 2:
                puts("O-|OO-OO");
            break;
            case 3:
                puts("O-|OOO-O");
            break;
            case 4:
                puts("O-|OOOO-");
            break;
            case 5:
                puts("-O|-OOOO");
            break;
            case 6:
                puts("-O|O-OOO");
            break;
            case 7:
                puts("-O|OO-OO");
            break;
            case 8:
                puts("-O|OOO-O");
            break;
            case 9:
                puts("-O|OOOO-");
            break;
        }
        n/=10;
    }
    return 0;
}
