//map
#include<cstdio>
#include<map>
using namespace std;

char cti[26] = {'2', '2', '2', '3','3', '3', '4', \
                    '4','4', '5', '5', '5','6', '6', '6',\
                     '7','2', '7', '7', '8','8', '8', '9', '9','9','9'};
int main(){

    int n, val = 0;
    char num[200];
    map<int, int> m;
    scanf("%d", &n);
    while(n--){
        scanf("%s", num);
        for(int i=0; num[i]; i++){
            if(num[i] != '-'){
                if(num[i] > '9')
                    num[i] = cti[num[i] - 'A'];
                val =val*10 + num[i] - '0';
            }
        }
        m[val]++;
        val = 0;
    }
    int cnt = 0;
    for(map<int,int>::iterator itr = m.begin(); itr != m.end(); ++itr){
        if(itr->second >1){
            printf("%03d-%04d %d\n", itr->first/10000, itr->first%10000, itr->second);
            cnt++;
        }
    }
    if(!cnt)
        printf("No duplicates.\n");

    return 0;
}
