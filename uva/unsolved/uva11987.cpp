#include<cstdio>

struct Nd{
    int p, r, num;
    vector<int> v;
};
int n, m;

bool init(){
    if(scanf("%d%d", &n, &m) == EOF)
        return false;
    for(int i=1; i<=n; i++){
        nd[i].p = i;
        nd[i].r = 0;
        nd[i].num = 1;
        nd[i].v.clear();
        nd[i].v.push_back(i);
    }
}

int findset(int x){
    return nd[x].p==x ? x : nd[x].p=findset(nd[x].p);
}

void uni(int a, int b){
    if(a == b) return ;
    if(nd[a].r > nd[b].r){
        nd[b].p = a;
        nd[a].num += nd[b].num;
        for(int i=0; i<nd[b].v.size(); i++)
            nd[a].v.push_back(nd[b].v[i]);
    }else{
        nd[a].p = b;
        nd[b].num += nd[a].num;
        for(int i=0; i<nd[a].v.size(); i++)
            nd[b].v.push_back(nd[a].v[i]);
        if(nd[a].r == nd[b].r)
            nd[b].r++;
    }
}

void leave(int a, int b){
    if(a != b){

    }
}
void sol(){
    int cmd, a, b;
    for(int i=0; i<m; i++){
        scanf("%d", &cmd);

        if(cmd == 1){
            scanf("%d%d", &a, &b);
            uni(findset(a), findset(b));
        }else if(cmd == 2){
            scanf("%d%d", &a, &b);
            leave(findset(a), a);
            uni(findset(a), findset(b));
        }else if(cmd == 3){
            scanf("%d", &a);
            printf("%d\n", nd[findset(a)].num);
        }
    }
}
int main(){
    while(init())
        sol();
    return 0;
}
