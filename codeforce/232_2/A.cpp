#include<cstdio>
int e, stu[101][2];
int cal(int ml, int mr, int dep){
    int l = stu[dep][0], r = stu[dep][1];
    if(dep == e)
        return mr - ml;
    if(l <= ml && r >= mr)
        return 0;
    else if(l > ml && l <= mr && r >= mr)
        return cal(ml, l, dep+1);
    else if(l <= ml && r < mr && r >= ml)
        return cal(r, mr, dep+1);
    else if(l > ml && l <= mr && r < mr && r >= ml)
        return cal(ml, l, dep+1) + cal(r, mr, dep+1);
    return cal(ml, mr, dep+1);
}
int main(){
    int n, ml, mr, sum;
    scanf("%d", &n);
    scanf("%d%d", &ml, &mr);
    n--;
    sum = mr - ml;
    for(e=0; e<n; e++)
        scanf("%d%d", &stu[e][0], &stu[e][1]);
    printf("%d\n", cal(ml, mr, 0));
    return 0;
}
