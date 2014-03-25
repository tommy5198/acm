#include<cstdio>

bool init(){
    scanf("%d", &n);
    if(!n) return false;
    for(int i=0; i<n; i++){
        scanf("%d%d%d", tmp, tmp+1, tmp+2);
        sort(tmp, tmp+3);
        if(ex[tmp[0]][tmp[1]])
            b[ex[tmp[0]][tmp[1]]].z = max(b[ex[tmp[0]][tmp[1]]].z, tmp[2]);
        else{
            ex[tmp[0]][tmp[1]] = k;
            b[k].x = tmp[0];
            b[k].y = tmp[1];
            b[k++].z = tmp[2];
        }
        if(ex[tmp[0]][tmp[2]])
            b[ex[tmp[0]][tmp[2]]].z = max(b[ex[tmp[0]][tmp[2]]].z, tmp[1]);
        else{
            ex[tmp[0]][tmp[2]] = k;
            b[k].x = tmp[0];
            b[k].y = tmp[2];
            b[k++].z = tmp[1];
        }
        if(ex[tmp[1]][tmp[2]])
            b[ex[tmp[1]][tmp[2]]].z = max(b[ex[tmp[1]][tmp[2]]].z, tmp[0]);
        else{
            ex[tmp[1]][tmp[2]] = k;
            b[k].x = tmp[1];
            b[k].y = tmp[2];
            b[k++].z = tmp[0];
        }
    }
    return true;
}

int main(){
    while(init())
    return 0;
}
