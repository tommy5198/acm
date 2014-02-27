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

void add(Node *now, Node *n){
    if(now->num > n->num){
        if(now->L)
            add(now->L, n);
        else
            now->L = n;
    }else{
        if(now->R)
            add(now->R, n);
        else
            now->R = n;
    }
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
        add(root, next);
    }
    post(root);
    free(root);
    return 0;
}
