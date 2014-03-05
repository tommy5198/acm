#include<cstdio>
#include<cstring>
#include<algorithm>

struct Str{
    char str[100];
    bool les(const char *a, const char *b)const{
        int al = strlen(a), bl = strlen(b);
        int mal = std::max(al, bl), mil = std::min(al, bl);
        for(int i=0; i<mil; i++){
            if(a[i] < b[i])
                return true;
            else if(a[i] > b[i])
                return false;
        }
        if(al > bl)
            return les(a+mil, b);
        else if(al < bl)
            return les(a, b+mil);
        return true;
    }

    bool operator<(const Str &t)const{
        return les(str, t.str);
    }
} str[51];


int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        if(!n)
            break;
        memset(str, 0, sizeof(str));
        for(int i=0; i<n; i++)
            scanf("%s", str[i].str);
        std::sort(str, str+n);
        for(int i=n-1; i>=0; i--)
            printf("%s", str[i].str);
        printf("\n");
    }
    return 0;
}
