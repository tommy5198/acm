#include<cstdio>

int main(){
    char str[200001], pre;
    int cnt = 0;
    bool isd = false;
    scanf("%s", str);
    pre = str[0];
    cnt = 1;
    for(int i=1; str[i]; i++){
        if(str[i] == pre)
            cnt++;
        else
            cnt = 1;
        pre = str[i];
        if(cnt == 2){
            if(isd){
                str[i] = 1;
                isd = false;
            }else
                isd = true;
        }else if(cnt > 2)
            str[i] = 1;
    }
    for(int i=0; str[i]; i++)
        if(str[i] != 1)
            printf("%c", str[i]);

    return 0;
}
