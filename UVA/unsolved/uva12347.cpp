#include<cstdio>
#include<cstdlib>
struct Node{
    int num;
    Node *L, *R, *P;
    void init(int n){
        num = n;
        L = R = P = NULL;
    }
}*root, *now, *next;

void post(Node *n){
    if(!n)
        return ;

    post(n->L);
    if(n->L)
        free(n->L);
    post(n->R);
    if(n->R)
        free(n->R);
    printf("%d\n", n->num);
}
int main(){
    int tmp;
    scanf("%d", &tmp);
    now = (Node*)malloc(sizeof(Node));
    now->init(tmp);
    root = now;
    while(scanf("%d", &tmp) != EOF){
        next = (Node*)malloc(sizeof(Node));
        next->init(tmp);

        if(tmp < now->num){
            next->P = now;
            now->L = next;
            now = next;
        }else{
            while(now->P && now->P->num > tmp)
                now = now->P;
            next->P = now;
            now->R = next;
            now = next;
        }
    }
    post(root);
    free(root);
    return 0;
}
