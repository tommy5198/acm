#include<cstdio>

struct OBJ{
    int x, y, z, v;

};

OBJ balloon[2000];
OBJ light[15];
int E[3];
int n, m, r;

bool iscross(int a, int b){
    OBJ &ba = balloon[b];
    OBJ &li = light[a];
    
    double oa = dis(ba.x, ba.y, ba.z, E[0], E[1], E[2]);
    double ob = dis(ba.x, ba.y, ba.z, li.x, li.y, li.z);
    double ab = dis(li.x, li.y, li.z, E[0], E[1], E[2]);
    if( oa < ba.v && ob < ba.v || oa < ba.v && ob > ba.v || oa > ba.v && ob < ba.v)
        return false;
    else{
        double h = (oa+ob+ab)/2;
        h = sqrt(h*(h-oa)*(h-ob)*(h-ab))/ab*2.;
        if(h > ba.v || oa > ob && oa*oa-h*h > ob*ob || ob > oa && ob*ob-h*h > oa*oa)
            return false;
    }
    return true;
}

void pre(){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(iscross(i, j))
                L[j/30] |= 1<<(j%30);
}

int calL(int x){
    int result = 0;
    for(int i=0; i<r; i++)
        if(x>>i)
            result += L[i];
    return result;
}

int recur(int now, int cnt){
    if(cnt == r)
        return 0;
    
    int result, Max = 0;
    for(int i=now+1; i<n; i++){
        result = calL(B[i]) + recur(i, cnt+1);
        Max = Max>result ? Max : result;
    }
    return Max;
}

int main(){
    
    while(scanf("%d%d%d", &n, &m, &r), n||m||r){
        for(int i=0; i<n; i++)
            scanf("%d%d%d%d", &balloon[i].x, &balloon[i].y, &balloon[i].z, &balloon[i].v);
        for(int i=0; i<m; i++){
            scanf("%d%d%d%d", &light[i].x, &light[i].y, &light[i].z, &light[i].v);
        }
        
        scanf("%d%d%d", E, E+1, E+2);
        pre();
        double result, Max = 0;
        for(int i=1; i < 1<<m; i++){
            for(int j=i, k = 0; j; j>>=1, k++)
                if(j&1) rm(k);
            for(int j=0; j<=n/30; j++)
                for(;cnt[j]; cnt[j]>>=1)
                    if(cnt[j]&1) result++;
               
        }
    }
    return 0;
}


